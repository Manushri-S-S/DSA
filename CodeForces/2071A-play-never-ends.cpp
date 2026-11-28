/*
APPROACH:

there are 3 members
playing tennis game
at a time only 2 can play
and the other have to watch the game(spectate)

but we have a condition
the first played players can continue the game at most 2 times
then they should spectate

so we are given a number n 
that is number of matches
initially one person spectates
we need to say
at nth match will the same person spectate

here we have a pattern
that is lets say the first  person playes 2 matches continuously
then 3rd  must be played by the spectator

so  at 4th match the other two player will play and spectator will spectate

so we do(n%3)==1
which means 4th match
(4%3)=1

the spectator will spectate

COMPLEXITY:
TIME:O(1)
we are following the pattern
SPACE:O(1)
we are not using extra space which depends on the input size



*/

#include<iostream>

int main(){

    int t;
    std::cin>>t;
    while(t>0){

        int n;
        std::cin>>n;

        if((n%3)== 1){
            std::cout<<"Yes\n";
        }else{
            std::cout<<"No\n";
        }
        t--;
    }


    return 0;
}