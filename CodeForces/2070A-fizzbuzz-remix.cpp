/*

APPROACH:

we are given a number and we need to find how many numbers
have same remainder if it is divided by 3 and 5

in brute force we are checking every number from 0 to n

COMPLEXITY:
TIME:O(n)
SPACE:O(1)

BRUTE FORCE:

#include<iostream>

int main(){

    int t;
    std::cin>>t;
    while(t>0){
        int n , count=0;
        std::cin>>n;

        for(int i = 0;i<=n;i++){
            if((i%3) == (i%5)){
                count++;
            }
        }
        std::cout<<count<<"\n";
        t--;
    }

    return 0;
}
*/

/*
OPTIMISED SOLUTION:

APPROACH:

brute force works fine
but we need optimised solution

we can see a pattern
that is the 
0 -> 1 ,2 , 
15 , 16 ,17 
30 , 31 , 32
are having same remainder with 3 and 5 division

we have 3 valid number for every 15 numbers

so (n/15)*3 gives the number

but need need to count 0 also so (n/15)*3+1

and we also need the check the valid number after (n/15)
like for example

n= 32

count = (32/15)*3 + 1
count =7
but valid count are 0 ,1,2,15,16,17,30,31,32

count = 9

so we need to check if(n%15 >=2)
we need to add 2 to it
that is after 30 we have 2 numbers 31 and 32

suppose n = 31
then we have only one number to add after count

so if(n%15) is less than 2
we add that number

COMPLEXITY:
TIME:O(1)
we are not traversing or looping
we are following the pattern

SPACE:O(1)
we not using extra space




*/

#include<iostream>


int main(){
    int t;
    std::cin>>t;

    while(t>0){
        int n , count = 1 , rem;
        std::cin>>n;

        count = (n/15)*3 + 1;

        if((n%15) >= 2){
            rem = 2;
        }else{
            rem = (n%15);
        }
        count = count + rem;

        std::cout<<count<<"\n";

        t--;
    }




    return 0;
}