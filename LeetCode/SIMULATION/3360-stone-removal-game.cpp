/*
APPROACH:

we are given a stone pile of n stones
alice and bob are playing with it
first alice starts the game
and removes 10 stones from n stones

then bob removes 9 stones fron the remaing n-10 stones

this goes on

if a person cant make a move they lose the game
we need to say if alice wins the game or not for the given n stone pile

we need tranfer control from alice to bob and bob to alice
so lets have flag 

if alice turns comes the flag will be 1
if bob has to make a move flag = 0

we are removing stones from n 
let i be initally 10
because alice always starts from removing 10 stones

and we go on removing stines so i--;


when n becomes negative or 0
whose turn to move next looses

so if flag is 0 at that time
bob looses and alice wins


COMPLEXITY:
TIME:O(n)
we are looping till we find negative value which depends on n
SPACE:O(1)
we are not using extra space
*/



class Solution {
public:
    bool canAliceWin(int n) {
        int flag = 1 , i = 10;
        while(n>=0){
            if(i%2 == 0){
                flag = 1;
            }else{
                flag = 0;
            }
            n = n-i;
            i--;
            
        }

        if(flag ==0 && n<0){
            return true;
        }else{
            return false;
        }
        
    }
};