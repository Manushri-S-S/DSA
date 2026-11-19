/*APPROACH:
just as the problem statement
we need count of every element in array
if that exceed (n/2)
we return that element
to keep count
we are using hash maps

COMPLEXITY:
TIME:O(n)
SPACE:O(1)

RUNTIME:40.01%
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>count;

        for(int i = 0;i<n;i++){
            count[nums[i]]++;
        }
        for(int i =0;i<n;i++){
            if(count[nums[i]] > (n/2)){
                return nums[i];
            }
        }

        return -1;
    }
};