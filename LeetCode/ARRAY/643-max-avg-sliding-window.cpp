/*APPROACH;
SLIDING WINDOW

we are taking sum of first k elements

and we are removing the first element and adding the next element
like 
ex:
a =[1, 2 , 2, 3]

k = 3

first we add 
sum = 1+2+2 = 5

then we keep it in prev for future comparision

then we move to next window
that is by removing first element of current window and add the next element of 
last of current window

sum = 5 - 1 + 3 = 7

now compare sum and prev
if it is larger we make prev = sum

then we take average using prev 

COMPLEXITY:
TIME:O(n)
SPACE:O(1)

runtime = 100%
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum , prev =0;
        int i=0;
        for(i =0;i<k;i++){
            prev += nums[i];
        }
         
        sum = prev;

        for(i=0;i+k<n;i++){
            prev = prev - nums[i] + nums[i+k];
            if(prev > sum){
                sum = prev;
            } 
        }
        
        return static_cast<double>(sum)/k ;
    }
};

