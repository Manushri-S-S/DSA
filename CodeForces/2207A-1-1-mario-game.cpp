#include <iostream>
using namespace std;
#include <string>

int main(){
    int t=0;
    cin>>t;

    for(int j = 1;j<=t;j++){
        int i ;
        int n ;
        cin>>n;
        string s;
        
        int mincount = 0 , maxcount = 0;

        cin>>s;
        
        string  maxstr = s;

        for(i =0;i+2<n;i++){
            if((maxstr[i]=='1' )&& (maxstr[i+2]=='1')){
                maxstr[i+1] ='1';
            }
            }
        
        string minstr = maxstr;
        for(i =0;i+2<n;i++){
            if((minstr[i]=='1' )&& (minstr[i+2]=='1')){
                minstr[i+1] ='0';
            }
            
            }
        
        
        for(i=0;i<n;i++){
            if(maxstr[i]== '1'){
                maxcount++;
            }
            if(minstr[i]=='1'){
                mincount++;
            }
        }
        cout<<mincount<<"  "<<maxcount<<endl;
    }

    return 0;
}