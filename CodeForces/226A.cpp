#include<iostream>
#include<vector>
using namespace std;

int main (){
    int num,i;
    cin>>num;
    for(i=0;i<num;i++){
        int j , n;
        
        cin>>n;
        int a[n];
        for(j=0;j<n;j++){
            cin>>a[j];
        }

        int k;
        int one = 0 , zero = 0;
        for(k=0;k<n;k++){
            
            if(a[k]==1){
                one++;
            }
            else{
                zero++;
            }
        }

        
        if(one>=zero){
            cout<<"Bessie"<<endl;
        }else{
            cout<<"Elsie"<<endl;
        }
    }
    return 0;
}