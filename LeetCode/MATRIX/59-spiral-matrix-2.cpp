/*
APPROACH:

we are given n integer
we need to generate a nXn spiral matrix from numbers 1 to n^2

for this 
we need to traverse the matrix in spiral
like 
first we move top row
then downward in right column
and to the left on the bottom row
finally towards up in the left row

after these steps we need shrink the outer boundary

so we do 
top++;
moved top from row 1 to row 2
left++;
moves left from column 1 to column 2
right--;
moves right from n to n-1 column
bottom--;
moves bottom from n to n-1 row

to push the element we need to have one shared variable 
which increments by 1 after each element

COMPLEXITY:
TIME:O(n^2) 
because we are traversing the whole 2d array of nXn 
SPACE:O(nXn)
we are creating an array of size nXn

RUNTIME:
100%


*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> a(n , vector<int>(n));
        int count = 1;

        int top = 0 , bottom = n-1 , left = 0 , right = n-1;
        while(top<=bottom && left<=right){
            //move left to right in top
            for(int i = left;i<=right;i++ ){
                a[top][i]=count;
                count++;
            }
            top++;

            //move top to bottom in right
            for(int i = top;i<=bottom;i++){
                a[i][right]=count;
                count++;
            }
            right--;

            //move right to left in bottom
            for(int i = right;i>= left;i--){
                a[bottom][i]=count;
                count++;
            }
            bottom--;

            //move bottom to top in left
            for(int i = bottom;i>=top;i--){
                a[i][left]=count;
                count++;
            }
            left++;

        }
        return a;
        
    }
};