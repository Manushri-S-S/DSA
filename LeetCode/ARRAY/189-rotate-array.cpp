/*
APPROACH:

we are given an array and int k 
we need to rotate the array by k elements in clockwise order

we are taking a new vector of the same size

we are pushing the the elements after n-k index in the same order

then we are adding the elements from first till k

EX:
nums = [1,2,3,4,5,6,7]
k=3

in first loop
n = 7
ans =[5,6,7]

in second loop
ans=[5,6,7,1,2,3,4]

and we copy the array to the given array
nums = ans 


COMPLEXITY:
TIME:O(n)
we are traversing and copying the elements
worst would be k = n(reversing the whole array)

SPACE:O(n)
we are taking additional space 
ans

RUNTIME:11.3%


*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i , j ;
        k=k%n;
        vector<int> ans;
        for(i=n-k;i<n;i++){
            ans.push_back(nums[i]);
            
        }
            
            for(j=0;j<n-k;j++){
                ans.push_back(nums[j]);
        
            }
        nums = ans;
    }
};