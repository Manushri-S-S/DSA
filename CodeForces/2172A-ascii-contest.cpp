/*APPROACH:


we are given 3 numbers we need to find the difference between 
largest and smaller number if it is >= 10 we must print 
check again

else the middle number should be printed

COMPLEXITY:
TIME:O(1)
SPACE:O(1)

MISTAKE:
usually we use sort to sort the array items
i did a mistake in vector and normal array

in vector since it is a pointer we use
sort(v.begin(),v.end()) to sort

in array we use

sort(a , a+n) n size of array
*/

#include<iostream>
#include<algorithm>

int main(){


    int a[3];

    std::cin>>a[0]>>a[1]>>a[2];

    std::sort(a,a+3);

    if(a[2]-a[0] >=10){
        std::cout<<"check again\n";
    }
    else{
        std::cout<<"final "<<a[1]<<"\n";
    }
    return 0;
}