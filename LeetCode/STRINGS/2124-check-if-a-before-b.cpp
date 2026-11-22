/*
APPROACH:

we are given a string and we need to find if a appears after b
if it does then we return 0 else 1

so lets have flag which marks the first appearance of b
and its first accurence we check for a 
if it is found we return false
else true

COMPLEXITY:
TIME:O(n)
we are traversing the given string so it n
SPACE:O(1)
we are not using additional space

RUNTIME:100%
*/

class Solution {
public:
    bool checkString(string s) {
        
        int flag = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i] == 'b'){
                flag = 1;
            }
            if(flag==1 && s[i] =='a') {
                flag = 0;
                return false;

            }
        }
        return true;
    }
};