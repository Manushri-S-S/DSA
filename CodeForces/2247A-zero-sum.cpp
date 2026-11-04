#include<iostream>
#include<vector>
/*
APPROACH:

to get sum of all numbers to zero
we need equal number of +1 and -1
 
we can perform the following operation

we can select any index i
and make ai =-ai and ai+1 = - ai+1

that we have to change the next element also in pair

instead of brute force
we can have a different approach

that is by counting number of +1 and -1 in the array

if we have equal number of pc(+1 count) and nc(-1 count)
we can have zero sum

else if we have nc as even 
by performing the operation we can make it equal

and for that we need number o array elements to be even

that is n should be even and nc should be even

but buttttt
we have a edge case
a =[1,1]

here if we perform the operation any nnumber of times 
we wont get the output zero even though nc =0 (even)

for that we need to find (nc - n/2) is even
if yes we get zero sum

*/
int main(){

    int t =0;
    std::cin>>t;
    for(int z=1;z<=t;z++){

        int n , i,nc=0,pc=0;
        std::cin>>n;

        std::vector<int> a(n);

        for(i=0;i<n;i++){
            std::cin>>a[i];

            if(a[i] == 1){
                pc++;
            }else{
                nc++;
            }
        }

        if(pc == nc){
            std::cout<<"YES"<<std::endl;
        }else if(((nc-(n/2)) %2 )==0 &&( n%2 == 0)){
            std::cout<<"YES"<<std::endl;
        }else{
            std::cout<<"NO"<<std::endl;
        }



    }
    return 0;
}