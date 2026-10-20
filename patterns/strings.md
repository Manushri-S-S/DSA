# Pattern: Counting Distinct Characters Using a Frequency/Seen Array

## 1. When to Use
Use this pattern when you need to:
- Count the number of unique/distinct characters in a string.
- Check whether a character has appeared before.
- Track which characters exist in a string without counting duplicates.

**Example:** `"abacaba"` contains 3 distinct characters: `a`, `b`, and `c`.

## 2. Core Idea
For a string containing only lowercase English letters, there are exactly 26 possible characters.

Create a Boolean array of size 26:
- `false` means the character has not appeared yet.
- `true` means the character has appeared at least once.

Map each character to an array index using:

```cpp
s[i] - 'a'
```

Examples:
- `'a' - 'a' = 0`
- `'b' - 'a' = 1`
- `'c' - 'a' = 2`

## 3. C++ Implementation

```cpp
bool seen[26] = {};

for (int i = 0; i < s.length(); i++) {
    seen[s[i] - 'a'] = true;
}

int distinct = 0;

for (int i = 0; i < 26; i++) {
    if (seen[i]) {
        distinct++;
    }
}
```

### How It Works
1. Initialize every entry to `false`.
2. Visit every character and mark its corresponding entry `true`.
3. Traverse the array and count the entries that are `true`.

Repeated characters overwrite `true` with `true`, so duplicates are automatically ignored.

## 4. Example Walkthrough

Input:

```text
abacaba
```

| Character | Index | Action |
|---|---:|---|
| `a` | 0 | Mark `seen[0] = true` |
| `b` | 1 | Mark `seen[1] = true` |
| `a` | 0 | Already seen; no new distinct character |
| `c` | 2 | Mark `seen[2] = true` |
| `a` | 0 | Already seen |
| `b` | 1 | Already seen |
| `a` | 0 | Already seen |

Only indices `0`, `1`, and `2` are true.

**Distinct character count = 3**

## 5. Important Initialization Lesson

Always initialize the array and counter:

```cpp
bool seen[26] = {};
int distinct = 0;
```

Local built-in arrays and integers are not automatically initialized to zero in ordinary C++ declarations. Uninitialized values can make your result unpredictable.

## 6. Complexity Analysis

Let \(n\) be the length of the string.

- **Time:** \(O(n + 26) = O(n)\)
- **Auxiliary space:** \(O(1)\), because the array always contains 26 entries.

## 7. Related Problem

**Codeforces 236A — Boy or Girl**

Count distinct characters in the username:
- Even number of distinct characters → `CHAT WITH HER!`
- Odd number of distinct characters → `IGNORE HIM!`

## 8. Pattern Recognition Cue

When a problem asks for the number of distinct lowercase letters, think:

**Boolean array → mark seen characters → count marked entries.**

### Limitations
This direct indexing approach assumes the characters are lowercase English letters (`a`–`z`). For uppercase letters, arbitrary characters, or Unicode text, the mapping or data structure needs to change.
