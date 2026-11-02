/*Approach
we are using an unorder map to keep the roman values in key value pair
because it doesnt add new element if not found

then we are traversing the string from left to right

if current value is less than the next 
we subtract current

else
we add current to sum

it happens till we get comparison that is loop will go till n-1

then we just add the last element



*/



class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int n = s.length();
        int sum =0;

        for(int i =0;i<n-1;i++){
            if(roman[s[i]]<roman[s[i+1]]){
                sum -= roman[s[i]];
            }else{
                sum+= roman[s[i]];
            }
        }

        sum += roman[s[n-1]];

       return sum;
        
    }
};