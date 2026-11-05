/*
APPROACH:

we need to check if the given array elements have even 
number of digits (not an even number)

for that lets have a traversal
where we check each numbers digit
if that digit is even
we increase the count

note:
for each iteration in traversal
remember to reinitialize dig =0
because we are counting digits for a new number every time

COMPLEXITY:
TIME:O(n)
SPACE:O(1)

runtime = 100 %
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int dig =0 , count=0;
        
        for(int i =0;i<n;i++){
            int num = nums[i];
            dig =0;
            while(num!=0){
                dig ++;
                num = (num/10);
            }
            if((dig%2) == 0){
                count++;
            }
        }
        return count;
    }
};