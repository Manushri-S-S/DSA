/*
APPROACH:
we are given four co ordinates
(-l,0)(r,o)(0,u)(0,-d)
l-left
r-right
u-up
d-down

we need to say if it forms a square(all sides must be equal)

we dont have to use distance formula

because the given co ordinates lie on the x and y axis

so just just check if all the co ordinates are equal to each other
if yes then it forms a square
else no

COMPLEXITY:
TIME:O(1)
we are just checking the points
SPACE:O(1)
we are using extra space



*/

#include<iostream>

int main(){
    int t ;
    std::cin>>t;

    while(t>0){
        int l , r , d , u;
        std::cin>>l>>r>>d>>u;

        if(l==r && r==d && d==u){
            std::cout<<"Yes\n";
        }else{
            std::cout<<"No\n";
        }
        t--;
    }

    return 0;
}