class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n =nums.size() , i;
        vector<int> ans;

        for(i=0;i<n;i++){
            
            int x = abs(nums[i]);
            if(nums[x-1]<0){
                continue;
            } 
            nums[x-1] = -nums[x-1];
            
        }
        for(i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
        
    }
};