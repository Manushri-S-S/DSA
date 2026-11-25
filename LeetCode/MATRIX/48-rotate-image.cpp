/*
APPROACH:

we are given a square matrix of nXn
we need find its rotation 
like for ex

vector<vector<int>> matrix = 
{
{1, 2, 3}, 
{4, 5, 6},
{7, 8, 9}
};
its rotation (90 degree )would be

a = 
[
[7,4,1],
[8,5,2],
[9,6,3]
]

we need to look for pattern 
initially 1 was at (0,0) it moved to (0,2)
and 3 - (2,0)->(2,2)

in general
(i,j) → (j,n-1-i)

we can arrive at this
by taking the transpose of the matrix

and reversing each row of the matrix

like in the example

transpose of a would be

{
{1, 4, 7}, 
{2, 5, 8},
{3, 6, 9}
}


reversing each row
like 
row 1 = {7 , 4 , 1}

then we will gets 90 degree rotation

COMPLEXITY:
TIME:O(n^2)
SPACE:O(1)

RUNTIME:
100%





*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        for(int i =0;i<n;i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
        
    }
};