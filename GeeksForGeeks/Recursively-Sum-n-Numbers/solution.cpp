class Solution {
  public:
    int recursiveSum(int n) {
        // Recursively sum from 1 to n and return
        // code here
        int i ,sum = 0;
        
        for(i =1;i<=n;i++){
            sum = sum + i;
        }
        
        return sum;
    }
};