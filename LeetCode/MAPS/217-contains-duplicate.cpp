/*
APPROACH:

we are given a int array we need to find if it has duplicates or not

to keep the number of occurence of different elemenets
we use maps

if it becomes >1 we say we have duplicates
else we say we dont have duplicates

COMPLEXITY:
TIME:O(n)//we are traversing the entire array

SPACE:O(n)

RUNTIME:24.29%

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int , int>count;
        for(int i =0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]] >1){
                return true;
            }
        }
        return false;
    }
};