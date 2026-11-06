#include<iostream>
/*APPROACH:
we are required to check if the string is plaindrome or not
also if it is not how many turns it takes to convert it into 
a palindrome for a given character

that is example
s = adfbc
given character ch = a

in first iteration
we check first and last element
a and c
we need to changes c to a

s = adfba

that is one turn (one coin)

second iteration
d and b are checked
we need both to change  to a
aafaa

now we dont need to check the middle element in an odd number
thats y we have loop condition
left(l)< right(r)
not left <= right(r)
because if it is given =
we need to compare f and f
and that would cost extra 2 cost than required

thats itttt
easyyyyyyyy

COMPLEXITY:
TIME:O(n)
SPACE:O(1)


*/
int main(){
    int t;
    std::cin>>t;
    for(int z= 1;z<=t;z++){
        int n;
        char ch;
        std::cin>>n>>ch;

        std::string s;
        std::cin>>s;

        int l = 0 , r = n-1 , coins =0;
        while(l<r){
            if(s[l] == s[r]){
                
            }else if(s[l] == ch || s[r]==ch){
                coins++;
            }else{
                coins += 2; 
            }
            l++;
            r--;
        }
        std::cout<<coins<<std::endl;

    }


    return 0;
}