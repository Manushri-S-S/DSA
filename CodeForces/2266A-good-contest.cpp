/*
APPROACH:

we are given the total number of participants
and this contest has 3 questons
easy , medium , hard

we say a player as weak if they couldnt solve all 3 problems

we need to say the number of weak players

for that
lets find the the question that is least attempted

then subtracting that with total no of players gives the no of weak players

COMPLEXITY:
TIME:O(1)
we are travesing the array of fixed size 3 and checking it
so it is constant time
SPACE:O(1)
we are using constant size


*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t>0){

        int n;
        cin>>n;

        vector<int> a(3);

        for(int i =0;i<3;i++){
            cin>>a[i];
        }

        int mn = *min_element(a.begin(), a.end());

        cout<<n-mn<<"\n";
        t--;
    }

    return 0;

}