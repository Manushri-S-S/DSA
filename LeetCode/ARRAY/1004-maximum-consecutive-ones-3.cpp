/*APPROACH:

we need to check the maximum number of ones with k or less than k zeroes

that is we can have maximum 1s with k 0s 

since we need contiguous element 
we need sliding window

we look for maximum continuous 1s with k zeros

lets have count to count 0s 

if it exceeds k 
we increment left
that is move to next window
note: we need to check the validity of the window before moving to next

that is the count of 0s should be <= k in the next window

for that lets have a loop
while(count >k){
    if(nums[left] == 0){
        count--;
    }
        left++;
}

this checks the validity

COMPLEXITIES:
TIME:O(n)
SPACE:O(1)

runtime:54.45%

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0 , right = 0;
        int count =0 , ans =0;
        for(right =0;right<n;right++){
            if(nums[right] == 0){
                count++;
            }

            while(count > k){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }

            int temp = right - left +1;

            if(temp > ans){
                ans = temp;
            }
        }
        return ans;
        
    }
};

