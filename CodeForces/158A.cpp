#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int score;
    vector<int> a (n);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    score = a[k-1];
    int count =0;
    for(i=0;i<n;i++){
        if(a[i]>=score && a[i]>0){
            count++;
        }
    }
    cout<<count;


    return 0;
}