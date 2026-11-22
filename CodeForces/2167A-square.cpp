/*APPROACH:

as we know for the definition of a square
we need all the four side of the polygon should be equal

we are given the the four sides of the polygon
we need to say if it is a square or not

we need to check one side with other 3 sides
if all of them are equal we say
it is a square
else no

COMPLEXITY:
TIME:O(n)

we are checking this operation for the given input testcase

SPACE:O(1)
we are not using extra space so its constant


*/

#include<iostream>

int main(){
    int t;
    std::cin>>t;
    while(t>0){

        int w ,x , y , z;

        std::cin>>w>>x>>y>>z;

        if(w==x && w==y && w==z){
            std::cout<<"YES\n";
        }else{
            std::cout<<"NO\n";
        }

        t--;
    }


    return 0;
}