#include<iostream>
#include <string>
using namespace std;


int main(){
    string s;

    cin>>s;
    int n = s.length();
    bool seen[26] = {};
    int i = 0;
    for(i=0;i<n;i++){
        seen[s[i] - 'a'] = true;
    }
    int count = 0;
    for(i = 0;i<26;i++){
        if(seen[i]==true){
            count++;
        }
    }

    if(count%2==0){
        cout<<"CHAT WITH HER!";
    }else{

        cout<<"IGNORE HIM!";
    }
    return 0;
}