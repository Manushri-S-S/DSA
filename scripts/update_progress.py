#!/usr/bin/env python3
"""Regenerate README statistics and SVG charts from progress.csv."""
import csv
from datetime import date, timedelta
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CSV_PATH = ROOT / "progress.csv"
README_PATH = ROOT / "README.md"
ASSETS = ROOT / "assets"

# Historical progress before daily dashboard tracking began.
BASELINE_LEETCODE = 54
BASELINE_CODEFORCES = 11
BASELINE_ACTIVE_DAYS = 34


def load_progress():
    daily = {}
    with CSV_PATH.open(newline="", encoding="utf-8") as file:
        reader = csv.DictReader(file)
        required = {"date", "leetcode_solved", "codeforces_solved", "notes"}
        if not required.issubset(reader.fieldnames or []):
            raise ValueError("CSV headers must be date,leetcode_solved,codeforces_solved,notes")
        for line_number, row in enumerate(reader, start=2):
            day = date.fromisoformat(row["date"].strip())
            lc, cf = int(row["leetcode_solved"]), int(row["codeforces_solved"])
            if lc < 0 or cf < 0:
                raise ValueError(f"Negative count on CSV line {line_number}")
            if day in daily:
                raise ValueError(f"Duplicate date on CSV line {line_number}: {day}")
            daily[day] = {"leetcode": lc, "codeforces": cf}
    return dict(sorted(daily.items()))


def streaks(active_dates):
    if not active_dates:
        return 0, 0
    active = set(active_dates)
    longest = run = 0
    previous = None
    for day in active_dates:
        run = run + 1 if previous and day == previous + timedelta(days=1) else 1
        longest = max(longest, run)
        previous = day
    latest = active_dates[-1]
    current = 0
    if latest in (date.today(), date.today() - timedelta(days=1)):
        current = 1
        cursor = latest - timedelta(days=1)
        while cursor in active:
            current += 1
            cursor -= timedelta(days=1)
    return current, longest


def svg_chart(title, labels, values, color, line=False):
    width, height = 900, 320
    left, right, top, bottom = 58, 24, 48, 54
    plot_w, plot_h = width - left - right, height - top - bottom
    if not values:
        return (
            f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}">'
            '<rect width="100%" height="100%" rx="14" fill="#0d1117"/>'
            f'<text x="28" y="34" fill="#f0f6fc" font-size="20" font-family="Arial">{title}</text>'
            f'<text x="{width/2}" y="{height/2}" text-anchor="middle" fill="#8b949e" font-size="16" font-family="Arial">Add your first entry to progress.csv</text></svg>'
        )
    maximum = max(1, max(values))
    count = len(values)
    coords = []
    for i, value in enumerate(values):
        x = left + (i + 0.5) * plot_w / count
        y = top + plot_h - (value / maximum) * plot_h
        coords.append((x, y))
    parts = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}">',
        '<rect width="100%" height="100%" rx="14" fill="#0d1117"/>',
        f'<text x="28" y="34" fill="#f0f6fc" font-size="20" font-family="Arial">{title}</text>',
    ]
    for tick in range(5):
        y = top + plot_h - tick * plot_h / 4
        parts.append(f'<line x1="{left}" y1="{y:.1f}" x2="{width-right}" y2="{y:.1f}" stroke="#30363d"/>')
        parts.append(f'<text x="{left-10}" y="{y+4:.1f}" text-anchor="end" fill="#8b949e" font-size="11" font-family="Arial">{maximum*tick/4:g}</text>')
    if line:
        pts = " ".join(f"{x:.1f},{y:.1f}" for x, y in coords)
        parts.append(f'<polyline points="{pts}" fill="none" stroke="{color}" stroke-width="3" stroke-linecap="round" stroke-linejoin="round"/>')
        for x, y in coords:
            parts.append(f'<circle cx="{x:.1f}" cy="{y:.1f}" r="4" fill="{color}"/>')
    else:
        bar_w = max(3, min(34, plot_w / count * 0.62))
        for x, y in coords:
            bar_h = top + plot_h - y
            parts.append(f'<rect x="{x-bar_w/2:.1f}" y="{y:.1f}" width="{bar_w:.1f}" height="{bar_h:.1f}" rx="3" fill="{color}"/>')
    step = max(1, count // 8)
    for i, label in enumerate(labels):
        if i % step == 0 or i == count - 1:
            x = left + (i + 0.5) * plot_w / count
            parts.append(f'<text x="{x:.1f}" y="{height-22}" text-anchor="middle" fill="#8b949e" font-size="10" font-family="Arial">{label}</text>')
    parts.append("</svg>")
    return "\n".join(parts)


def main():
    progress = load_progress()
    ASSETS.mkdir(exist_ok=True)
    if progress:
        first, last = min(progress), max(progress)
        days, cursor = [], first
        while cursor <= last:
            days.append(cursor)
            cursor += timedelta(days=1)
        lc = [progress.get(d, {}).get("leetcode", 0) for d in days]
        cf = [progress.get(d, {}).get("codeforces", 0) for d in days]
        daily = [a + b for a, b in zip(lc, cf)]
        cumulative, running = [], 0
        for value in daily:
            running += value
            cumulative.append(running)
        labels = [d.strftime("%d %b") for d in days]
        active_dates = [d for d, count in zip(days, daily) if count > 0]
        current, longest = streaks(active_dates)
        active_days = len(active_dates)
        total_lc, total_cf = sum(lc), sum(cf)
    else:
        labels, daily, cumulative = [], [], []
        total_lc = total_cf = active_days = current = longest = 0

    (ASSETS / "daily-progress.svg").write_text(svg_chart("Problems solved per day", labels, daily, "#58a6ff"), encoding="utf-8")
    (ASSETS / "cumulative-progress.svg").write_text(svg_chart("Cumulative problems solved", labels, cumulative, "#3fb950", line=True), encoding="utf-8")
    stats = {
        "LeetCode problems solved": str(BASELINE_LEETCODE + total_lc),
        "Codeforces problems solved": str(BASELINE_CODEFORCES + total_cf),
        "Total problems solved": str(BASELINE_LEETCODE + BASELINE_CODEFORCES + total_lc + total_cf),
        "Active problem-solving days": str(BASELINE_ACTIVE_DAYS + active_days),
        "Current streak": f"{current} days",
        "Longest tracked streak": f"{longest} days",
    }
    lines = README_PATH.read_text(encoding="utf-8").splitlines()
    for i, line in enumerate(lines):
        for label, value in stats.items():
            if line.startswith(f"| {label} |"):
                lines[i] = f"| {label} | {value} |"
    README_PATH.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("Dashboard updated:")
    for label, value in stats.items():
        print(f"  {label}: {value}")


if __name__ == "__main__":
    main()
