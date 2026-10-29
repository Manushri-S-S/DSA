#include<iostream>
#include<string.h>
using namespace std;

int main (){
    int t ;
    cin>>t;

    for(int i =0;i<t;i++){
        string s;
        cin>>s;

        int n = s.length();
        if(n>10){
            s = s[0]+ to_string(n-2) + s[n-1];
        }

        cout<<s<<endl;
    }


    return 0;
}