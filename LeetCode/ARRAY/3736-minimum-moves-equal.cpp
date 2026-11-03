/*Approach
we need equalize all the elements by only incrementing it
which means we have to increment every element to its max val

for that we need traversal
we take one element at a time
and check it with max

if it not equal to max
we increment it and the count variable

by that way every element will be equal to max

COMPLEXITY:
TIME : O(n);
SPACE:O(1);

runtime : 13.31 %
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;

        for(int i =0;i<n;i++){
            
            while(nums[i] != max){
                count++;
                nums[i]++;
            }   
        }
        return count;
    }
};