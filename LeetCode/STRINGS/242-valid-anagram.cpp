/*APPROACH:


we are given 2 strings we need to check if they are anagram or not

anagram:the count of each characters in both the strings must be equal

so what we do is 
since the string contains only lower case english letters
lets have a count array of 26 for lower case letters

we check both the string length if they are not equal it is not a anagram

the main concept
using one traversal we increase and decrease the count 
that is
we increase the count for first string in count array
and decrease the count for second string in count array

traversing the count array
if we have a value other than 0 then it is not an anagram

because if they both have same number of characters
each would get cancelled out during increasing dcreasing process

so it is a anagram the count array would be 0

MISTAKES i made:
syntax error 
vector<int> count(26)={0};
actually it should be
vector<int> count(26);
thats it


COMPLEXITY:
TIME:O(n)
SPACE:O(1)

runtime:62.21%
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);

        int n = s.length();
        int m = t.length();

        if(m!=n){
            return 0;
        }  

        for(int i = 0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }     

        for(int i=0;i<26;i++){
            if(count[i] != 0){
                return 0;
            }
        }
        return 1;
    }
};