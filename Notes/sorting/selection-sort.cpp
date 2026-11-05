#include<iostream>
#include <vector>
/*
approach

we need to find the minimum value index in every traversal
and swap with i that is from brginning

this is unstable
that is
a =[3 , 4a,4b]

after sorting
a = [3 , 4b , 4a]
the relative order is not maintained
*/

int main(){

    std::vector<int> arr = {64, 25, 12, 22, 11};

    int i = 0 , j= 0;
    int n = arr.size();

    for(i =0;i<n;i++){
        int min = i;
        for(j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(i = 0;i<n;i++)
        std::cout<<arr[i]<<"  ";


    return 0;
}