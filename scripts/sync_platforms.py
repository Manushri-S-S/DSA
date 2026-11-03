#!/usr/bin/env python3
"""Read-only public-profile sync for LeetCode and Codeforces."""
import csv, json, os, sys, urllib.request
from collections import defaultdict
from datetime import date, datetime, timezone
from pathlib import Path
from zoneinfo import ZoneInfo

ROOT = Path(__file__).resolve().parents[1]
CSV_PATH = ROOT / "progress.csv"
STATE_PATH = ROOT / "data" / "platform_state.json"
LC_USER = os.getenv("LEETCODE_USERNAME", "Manushri-S-S")
CF_HANDLE = os.getenv("CODEFORCES_HANDLE", "manu21208shri")
BASELINE_LC = 54
TRACKING_START = date(2026, 11, 3)
IST = ZoneInfo("Asia/Kolkata")


def get_json(url, payload=None, headers=None):
    h = {"User-Agent": "DSA-Progress-Tracker/1.0"}
    if headers: h.update(headers)
    data = None
    if payload is not None:
        data = json.dumps(payload).encode()
        h["Content-Type"] = "application/json"
    req = urllib.request.Request(url, data=data, headers=h)
    with urllib.request.urlopen(req, timeout=25) as r:
        return json.loads(r.read().decode())


def leetcode_total():
    query = """query userPublicProfile($username: String!) { matchedUser(username: $username) { submitStats { acSubmissionNum { difficulty count } } } }"""
    result = get_json("https://leetcode.com/graphql/", {"query": query, "variables": {"username": LC_USER}},
                      {"Referer": f"https://leetcode.com/u/{LC_USER}/", "Origin": "https://leetcode.com"})
    user = (result.get("data") or {}).get("matchedUser")
    if not user or result.get("errors"):
        raise RuntimeError(f"LeetCode profile/API unavailable: {result.get('errors', 'profile not found')}")
    rows = user["submitStats"]["acSubmissionNum"]
    for row in rows:
        if row["difficulty"] == "All": return int(row["count"])
    return sum(int(x["count"]) for x in rows)


def codeforces_solved():
    url = f"https://codeforces.com/api/user.status?handle={CF_HANDLE}&from=1&count=10000"
    result = get_json(url)
    if result.get("status") != "OK":
        raise RuntimeError(f"Codeforces API error: {result.get('comment')}")
    earliest = {}
    for sub in result.get("result", []):
        if sub.get("verdict") != "OK": continue
        p = sub.get("problem") or {}
        if p.get("contestId") is None or not p.get("index"): continue
        key = f"{p['contestId']}-{p['index']}"
        ts = int(sub.get("creationTimeSeconds", 0))
        earliest[key] = min(ts, earliest.get(key, ts))
    return earliest


def load_rows():
    rows = {}
    with CSV_PATH.open(newline="", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        required = {"date", "leetcode_solved", "codeforces_solved", "notes"}
        if not required.issubset(reader.fieldnames or []):
            raise RuntimeError("Unexpected progress.csv headers")
        for r in reader:
            d = date.fromisoformat(r["date"].strip())
            if d in rows: raise RuntimeError(f"Duplicate CSV date: {d}")
            rows[d] = {"leetcode_solved": int(r["leetcode_solved"] or 0),
                       "codeforces_solved": int(r["codeforces_solved"] or 0), "notes": r.get("notes", "")}
    return rows


def add_count(rows, day, column, count):
    if count <= 0 or day < TRACKING_START: return
    if day not in rows: rows[day] = {"leetcode_solved": 0, "codeforces_solved": 0, "notes": "Automatically synced"}
    rows[day][column] += count
    label = "LeetCode" if column.startswith("leetcode") else "Codeforces"
    note = f"Auto-synced {count} {label} problem(s)"
    if note not in rows[day]["notes"]: rows[day]["notes"] = (rows[day]["notes"] + "; " + note).strip("; ")


def main():
    # Fetch both APIs before mutating local files; a failed request won't advance checkpoints.
    lc_now = leetcode_total()
    cf_now = codeforces_solved()
    rows = load_rows()
    state = json.loads(STATE_PATH.read_text()) if STATE_PATH.exists() else None

    if state is None:
        # Baseline plus already logged CSV solves prevents the initial sync duplicating them.
        lc_seen = BASELINE_LC + sum(x["leetcode_solved"] for x in rows.values())
        cf_seen = set(cf_now)  # snapshot all current CF solves as historical on first sync
        new_cf = defaultdict(int)
        print(f"First sync: recorded {len(cf_seen)} existing Codeforces problems as historical.")
    else:
        lc_seen = int(state.get("leetcode_total_seen", BASELINE_LC))
        cf_seen = set(state.get("codeforces_problem_ids", []))
        new_cf = defaultdict(int)
        for pid, ts in cf_now.items():
            if pid in cf_seen: continue
            cf_seen.add(pid)
            day = datetime.fromtimestamp(ts, timezone.utc).astimezone(IST).date()
            if day >= TRACKING_START: new_cf[day] += 1

    lc_delta = max(0, lc_now - lc_seen)
    if lc_delta:
        # LeetCode public profile gives a total, not a complete dated unique-AC history.
        add_count(rows, datetime.now(IST).date(), "leetcode_solved", lc_delta)
    for day, count in new_cf.items(): add_count(rows, day, "codeforces_solved", count)

    with CSV_PATH.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["date", "leetcode_solved", "codeforces_solved", "notes"])
        w.writeheader()
        for day in sorted(rows):
            w.writerow({"date": day.isoformat(), **rows[day]})

    STATE_PATH.parent.mkdir(parents=True, exist_ok=True)
    state_out = {"leetcode_username": LC_USER, "leetcode_total_seen": max(lc_seen, lc_now),
                 "codeforces_handle": CF_HANDLE, "codeforces_problem_ids": sorted(cf_seen),
                 "last_synced_utc": datetime.now(timezone.utc).isoformat(timespec="seconds")}
    STATE_PATH.write_text(json.dumps(state_out, indent=2) + "\n", encoding="utf-8")
    print(f"LeetCode total: {lc_now}; newly detected: {lc_delta}")
    print(f"Codeforces unique accepted problems seen: {len(cf_seen)}; new: {sum(new_cf.values())}")


if __name__ == "__main__":
    try: main()
    except Exception as e:
        print(f"SYNC FAILED: {e}", file=sys.stderr)
        sys.exit(1)
