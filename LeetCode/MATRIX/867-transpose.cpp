/*
APPROACH:

we need to find the transpose of given matrix 
transpose: the rows and column element are inter changed

for that we need a new 2d array
because 2X3 transpose will be 3X2

we are having m as no of rows of the given matrix
n - no of columns

for transpose we need nXm matrix

we are having 2 nested loops 

outer for rows and inner for column

MISTAKE:
since outer loop is for rows and inner for columns
we need to have a[j][i] = matrix[i][j]

or else we will get outer bound access error

COMPLEXITY:
TIME:O(mXn)
SPACE:O(mXn)

RUNTIME:100%

*/


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> a(n,vector<int> (m,0));

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                a[j][i] = matrix[i][j];
            }
        }
        return a;
    }
};