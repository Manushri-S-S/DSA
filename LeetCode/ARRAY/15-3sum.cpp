/*
APPROACH:

first we sort the  array 
so that finding other elements is easy

we fix one element i 
and we check the other two elements
using binary search

if the sum is greater than 0
that means we need smaller number
we make right--

if sum <0 
that means we need larger number
so we make left ++

if it is equal to 0
we add those 3 numbers to ans 2d vector

buttttttttttt🍑
we dont need repeated triplets in our ans
so we add a checking condition 
we need to increment left and decrement right till we find a unique
since the array is sorted just by comparing adjacent value
we can do that 

else {
        ans.push_back({nums[i], nums[left], nums[right]});
            left++;
            right--;

            while(left < right && nums[left] == nums[left - 1])
                left++;

            while(left < right && nums[right] == nums[right + 1])
                right--;
}

we also need to check the fixed element 
if we already checked for that value
we can just move to next

if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
}

here i>0 is imp
because for i =0 we dont have i-1 index that is invalid

COMPLEXITIES:
TIME:O(n^2)
SPACE:O(1)

runtime:41.61%

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i , left , right ;
        int n = nums.size();
        vector<vector<int>> ans;
        for(i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left = i+1;
            right = n-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];

                if(sum<0){
                    left++;
                }else if(sum>0){
                    right--;
                }else {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left - 1])
                        left++;

                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;

    }
};