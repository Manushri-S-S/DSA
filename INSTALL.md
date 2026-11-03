# Install the DSA progress automation

This bundle adds:
- `scripts/sync_platforms.py`: reads public LeetCode and Codeforces data.
- `.github/workflows/sync-dsa-progress.yml`: runs every six hours and supports manual runs.

## Install

1. Extract the ZIP into the **root** of your existing `Manushri-S-S/DSA` repository. Merge the `scripts` and `.github` folders. Keep your existing `scripts/update_progress.py`.
2. From the repository root, commit and push:

   ```bash
   git add scripts/sync_platforms.py .github/workflows/sync-dsa-progress.yml
   git commit -m "Add automatic DSA progress sync"
   git push
   ```

3. On GitHub, open **Actions** → **Sync DSA Progress** → **Run workflow** for the first sync.
4. Check that the workflow run completes successfully.

## Behavior and limitations

- **LeetCode:** reads the public profile's accepted-problem total. Increases are logged on the date detected by the next sync. The public profile endpoint does not provide a complete, reliable dated history of all unique accepted problems, so the exact solve date may be unavailable.
- **Codeforces:** reads public submissions and deduplicates accepted problems by contest ID and problem index. On first sync, existing accepted problems are snapshotted as historical; future newly accepted problems are logged using their accepted date.
- The script preserves your baseline (54 LC, 11 CF, 34 historical LC active days) in the existing dashboard updater and respects existing rows in `progress.csv` to avoid counting your already logged solve twice.
- No passwords, cookies, API keys, or submission actions are used. Both integrations are read-only.
- If the first sync happens after a new Codeforces solve, it will be included in the initial historical snapshot. Add that solve manually to its date in `progress.csv` if you want it included in the new-tracking-period graph.
- The workflow requests `contents: write` to commit the updated CSV, sync state, README and charts. If pushing fails, check repository Settings → Actions → General → Workflow permissions and enable read and write permissions.
- GitHub may delay scheduled workflows during busy periods. Use **Run workflow** for an immediate sync.
