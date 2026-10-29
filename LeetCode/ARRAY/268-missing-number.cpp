/*approach

we know the size of the array is the the element
value but only one is missing

we can find that with the sum of integers from 1 to n
minus the sum of array elements

this gives the missing element because

ex: n =3
a = [0,1,3]

here 2 is missing
lets calculate the sum of 1 to 3 first 
1+2+3 = 6

and the array element sum is
0+1+3 = 4

so 6-4 = 2 that is the missing element

COMPLEXITY:
TIME:O(n) because we need traversal of the entire array
SPACE: O(1) 
run time:100%*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int i , sum = 0 , sum2 = 0;
        for(i=1;i<=n;i++){
            sum += i;
        }

        for(i =0;i<n;i++){
            sum2 += nums[i]; 
        }
        return sum-sum2;
    }
};

/*another approach 
using xor
remember:
a xor 0 = a
a xor a = 0

we can use only one loop 
sum ^= (i+1)^nums[i];

in that way 
only missing element will be left
because it is present only once that is in the i part
not nums[i] part
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int i , sum = 0 , sum2 = 0;
        for(i=0;i<n;i++){
            sum ^= (i+1)^nums[i];
        }

        
        return sum;
    }
};