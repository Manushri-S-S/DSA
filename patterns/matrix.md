# Matrix Patterns

## 1. Transpose
Pattern:
(i, j) → (j, i)

Key idea:
Rows and columns swap.

Useful for:
- Transpose Matrix
- Rotate Image

---

## 2. Rotate Matrix 90° Clockwise
Pattern:
1. Transpose
2. Reverse every row

Complexity:
O(n²) time
O(1) extra space

---

## 3. Spiral Traversal
Maintain four boundaries:

top
bottom
left
right

Traversal:
→ top++
↓ right--
← bottom--
↑ left++

Important:
Guard the last row/column to avoid duplicate traversal.

---

## 4. Matrix STL
matrix.size()
matrix[0].size()

vector<vector<int>>(m, vector<int>(n, 0))

reverse(...)
swap(...)
fill(...)
find(...)
reserve(...)

---

## 5. Grid Direction Pattern
4 directions:

dr = {1,-1,0,0}
dc = {0,0,1,-1}

Used for:
- Islands
- Flood Fill
- Grid DFS/BFS
- Shortest paths

