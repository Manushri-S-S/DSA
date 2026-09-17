class Solution {
  public:
    int nthFibonacci(int n) {
        
        if(n==0)
            return 0;
        // code here
       vector<int> ans;
       int i;
       ans.push_back(0);
       ans.push_back(1);
       for( i=2;i<=n;i++){
           int res = ans[i-1]+ans[i-2];
           ans.push_back(res);
           
           
       }
       int num = ans.size();
        
       return ans[num-1]; 
        
    }
};