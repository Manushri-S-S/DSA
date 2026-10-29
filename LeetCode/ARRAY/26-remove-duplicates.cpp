class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int key = nums[0];
        int k=0;
        
        for(int i = 0;i<n;i++){
            if(key != nums[i]){
                key = nums[i];
                k++;
                nums[k] = nums[i];
            }
        }
        k++;
        
        
        return k;
    }
};