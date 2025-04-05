#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i=0 ; i<n ; i++) cin>>a[i];


        int x = 1e9 , y = 1e9;
        int minScore = 0;
        for(int i=0 ; i<n ; i++){
            if( x > y ) swap(x , y);

            if( a[i] <= x ) x = a[i];
            else if( a[i] > y ){
                minScore++;
                x = a[i];
            }  
            else{
                y = a[i];
            }
        }

        cout<<minScore<<endl;
    }
}