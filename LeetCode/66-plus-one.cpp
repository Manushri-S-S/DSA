/*my approach
first add one to the last element then check if 
it is greater than 9 
since we are adding 1 it always will be 10
if it is 10 make last as 0 and add that one to 
the previous element
check the entire array 

edge case :
if we need one more element in the beginning
that is ex: 9 
9 + 1 = 10
we need array to be  [1,0]

we need to reallocate the given array
and add 1 as the first element

Complexity
Time : O(n);
Space:O(1);

run time :100%

*/




class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i;
        digits[n-1] += 1;

        for(i = n-1 ; i>0 ;i--){
            if(digits[i]>9){
                digits[i] = 0;
                digits[i-1] += 1;
            }
        }

        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};