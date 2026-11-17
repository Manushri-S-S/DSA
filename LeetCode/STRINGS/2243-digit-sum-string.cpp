/*
APPROACH:

we are given a string
and we need to group k elements and find its numeric sum

we need to continue this process 
till we get the string to be k letters

for this lets have a loop
till n>k
n is the string length

we can take k groups till n
and the the left numbers are considered even if ti is not equal to k


*/

class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        string t;
        while(n>k){
            for(int i=0;i<n;i=i+k){
                int j =i,sum=0, l=0;
                while(l<k && j!= n){
                    sum += s[j]-'0';
                    l++;
                    j++;
                }
                t.append(to_string(sum));

            }
            n = t.length();
            s = t;
            t.clear();

        }
        return s;
        
    }
};