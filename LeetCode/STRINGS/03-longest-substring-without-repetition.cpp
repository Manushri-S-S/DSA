/*APPROACH:
we need to find longest substring without any repeting 
characters
lets use sliding window 
because we need consecutive character for longest substring
and maps
because we need find sub string without repetion


we need traversal of string from the beginnig
and lets increment the frequency of that character using map

and add that character to sliding window

if that character has a repetition
we move our window to next element
and decrement the count

we can find the number of character just by subtracting
the index of sliding window

that is right - left +1 
+1 because array index starts from 0

if the current length of valid substring is grater than the previous
we make the current as the final answer

COMPLEXITY:
TIME:O(n)
SPACE:O(1)

runtime:41.69%
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {

        mp[s[right]]++;

        while (mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }

        int ans1 = right - left + 1;

        if (ans1 > ans) {
            ans = ans1;
        }
    }
    return ans;
        
    }
};