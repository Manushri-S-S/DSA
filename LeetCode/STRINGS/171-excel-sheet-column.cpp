
class Solution {
public:
    int titleToNumber(string columnTitle) {
    
        int n = columnTitle.length();
        int i , val , sum=0;
        for(i=0;i<n;i++){
            val = columnTitle[i]-'A'+1;
            sum = sum + pow(26,(n-i-1))*val;
        
        }

        
        return sum;
        
    }
};
