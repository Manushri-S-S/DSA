/*
APPROACH:
we are given an array with 0 and 1 o for easy problem and 1 for hard problem

in this contest we need to place 2 easy question in the beginning and in the end
we just need to calculate the number of swaps required to make first and last question as easy

for that we need to count the number of easy questions

if it is less than 2 
it is impossible to make them 

if it is atleast 2 we can make the first and last question easy

for that we need to check the already given question pattern
if it contains first and last question easy 
we dont need any swaps

if it has either one easy question in first or last
we need just one swap

if it doesnt have any easy question in th first or in the last
we need 2 swaps

thats it

COMPLEXITY:
TIME:O(n)
SPACE:O(n)

MISTAKES:
avoid accessing outer bound elements in array 





*/



#include<iostream>


int main(){
    int t;
    std::cin>>t;

    while(t>0){
        int n , i;
        std::cin>>n;
        int a[n] , count = 0;

        for(i =0;i<n;i++){
            std::cin>>a[i];
            if(a[i]==0){
                count++;
            }
        }

        if(count<2){
            std::cout<<"-1"<<std::endl;
        }else{
            if(a[0]==0 && a[n-1] == 0){
                std::cout<<"0"<<std::endl;
            }
            else if(a[0]==0 || a[n-1]==0 ){
                std::cout<<"1"<<std::endl;
            }else{
                std::cout<<"2"<<std::endl;
            }
        }


        t--;
    }
}

/*ANOTHER APPROACH:
COMPLEXITY:
TIME:O(n)
SPACE:O(1)

but less than the previous approach memory
we dont have array here


*/


#include<iostream>


int main(){
    int t;
    std::cin>>t;

    while(t>0){
        int n , i;
        std::cin>>n;

        /*further optimizing
        we can avoid the whole array itself
        since we need only first and last element and the count of zero*/

        int first =0 , last = 0 , count = 0;
        for(i =0;i<n;i++){
            std::cin>>last;
            if(i == 0){
                first = last;
            }
            if(last == 0){
                count++;
            }
        }

        /*here we are taking first and last element
        if i becomes 0 that is our first input
        we store it in first variable
        and last variable gets over writtern and it finally has the
        last element input in it stored*/

        if(count<2){
            std::cout<<"-1"<<std::endl;
        }else{
            if(first==0 && last == 0){
                std::cout<<"0"<<std::endl;
            }
            else if(first ==0 || last ==0 ){
                std::cout<<"1"<<std::endl;
            }else{
                std::cout<<"2"<<std::endl;
            }
        }


        t--;
    }
}



