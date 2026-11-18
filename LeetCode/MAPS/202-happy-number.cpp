/*
APPROACH:
happy number is a number if the sum of its digit square is equal to 1
we need to find that if a given number is happy or not

we can do this just by following the given procedure
find the sum of square of its digits
this is done by the inner  loop 

the outer loop is to carry this process till we get sum = 1 or
this is the important part

if a number is not happy number
ex:2
sum = 4
sum = 16 it goes on forever

we need to check its occurence
it the sum has occured twice
that means we are in a forever loop

so we need hash maps
to keep count of the sum frequency
if that is more than 1 
we can say it is not a happy number


COMPLEXITY:
TIME:O(n^2)
SPACE:(n)

RUNTIME:100%
*/


class Solution {
public:
    bool isHappy(int n) {
        int dig =0,sum =0;
        int t = n;
        unordered_map <int , int> count;

        while(sum!=1 && t < INT_MAX){
            sum =0;
            while(t>0){
                dig = (t%10);
                sum = sum + (dig*dig);
                t = (t/10);
            }
            count[sum]++;
            if(count[sum] >1){
                return false;
            }
            t = sum;
            
        }
        if(sum == 1){
            return true;
        }else{
            return false;
        }
       
    }
   
};