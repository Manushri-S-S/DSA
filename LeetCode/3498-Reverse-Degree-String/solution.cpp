class Solution {
public:
    int reverseDegree(string s) {
        int i , sum = 0 , code =0 ;
        int n = s.length();
        for(i=0;i<n;i++){
            code = ('z'-s[i]+1);
            sum = sum + ((i+1)*code);
        }
        return sum;
    }
};