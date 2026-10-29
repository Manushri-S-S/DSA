class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        

         for(int i = 0; i<n ; i++){

        int max = *max_element(nums.begin(),nums.begin()+i);
        int min = *min_element(nums.begin()+i,nums.end());
         
         int key = (max - min);
            if(key <= k){
                return i;
                
            }
                
         }

         return -1;

    }
};
