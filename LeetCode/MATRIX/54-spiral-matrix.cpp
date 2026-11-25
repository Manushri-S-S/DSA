/*
APPROACH:

we need to traverse the given 2d array spirally and make it 1D array 

to traverse spirally we need 4 variable

initially 
top at first row
bottom at last row
left at first column
right at last column

we start traversing the first row (top) left to right
and push the elements to our 1D array
now we are done with first row
so make top to point next row
by making
top++;

now we need to move top to bottom in right column
after finishing that 
we need to make right to point to back column
right--

now we move from right to left in bottom row
after done with that row
we need to make bottom move up
bottom++;

finally we shall traverse from bottom to top in left column
after that we need to make left to next column
left++

COMPLEXITY:
TIME:O(m*n)
because we are traversing the whole 2d array of mXn
SPACE:O(m*n)
we are using 1D array of m*n elements

RUNTIME:
100%


*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> a;
        int top = 0 , bottom = m-1 , left = 0 , right = n-1;

        while(top<=bottom && left<=right){
            //move left to right in top
            for(int i = left ; i<= right ; i++)
                a.push_back(matrix[top][i]);
            top++;

            //move top to bottom in right
            for(int i = top;i<= bottom;i++){
                a.push_back(matrix[i][right]);
            }
            right--;

            //move right to left in bottom
            if(top<=bottom){
                for(int i = right;i>=left;i--){
                    a.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            

            //move bottom to top in left

            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    a.push_back(matrix[i][left]);
                }
                left++;

            }
            

        }

        return a;
    }
};