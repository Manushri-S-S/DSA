#include<iostream>
#include <vector>



int main(){

    std::vector<int> arr = {64, 25, 12, 22, 11};

    int i = 0 , j= 0;
    int n = arr.size();

    for(i =0;i<n;i++){
        int key = arr[i];
        j=n-1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for(i = 0;i<n;i++)
        std::cout<<arr[i]<<"  ";


    return 0;
}