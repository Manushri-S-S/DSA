class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int i , j , sum =0, dig;
        for( i =0;i<n;i++){
            j = nums[i];
            sum = 0;
            while(j!=0){
                dig = (j%10);
                sum = sum + dig;
                j =(j/10);
            }
            cout<<sum;
            if(sum == i){
                return i;
            }
        }
        return {-1};
    }
};

