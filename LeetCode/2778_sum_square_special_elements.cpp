/*my approach is 
since the problem index is starting from 1
and array index starts from 0
we need traversal 
i used array index + 1 and summed array index if array length % array idx +1 */



class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int i, sum =0;
        for(i= 0;i<n;i++){
            if((n%(i+1)) == 0){
                sum = sum + (nums[i]*nums[i]);
            }
        }
        return sum;
    }
};