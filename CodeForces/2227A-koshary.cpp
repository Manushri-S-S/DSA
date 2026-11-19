/*
APPROACH:

we are starting from(0,0) we have to check whether we can reach
(x,y) given

for that allowed operation are

only one odd (1 step) in any direction through out the journey
any number of even 2 steps 

if the given co ordinates have 2 odd numbers

we cant reach there
because we are allowed to take only one odd step

so if both are odd 
answer - no
else
yes

COMPLEXITY:
TIME:O(1)
SPACE:O(1)


*/


#include<iostream>

int main(){
    int t;
    std::cin>>t;

    while(t>0){
        int x , y;
        std::cin>>x>>y;

        if(x%2 == 1 && y%2 == 1){
            std::cout<<"NO\n";
        }else{
            std::cout<<"YES\n";
        }


        t--;
    }


    return 0;
}