#include<bits/stdc++.h>
using namespace std;

#define ll long long

int minOp(int idx , vector<int>& a , vector<int>& dp){
    int n = a.size();
    if( idx > n ) return 1e9;
    if( idx == n ) return 0;

    if( dp[idx] != -1 ) return dp[idx];

    int pick = minOp( idx + a[idx] + 1 , a , dp );
    int nonPick = 1 + minOp( idx+1 , a , dp );

    return dp[idx] = min( pick , nonPick );
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0 ; i<n ; i++) cin>>a[i];

        vector<int> dp( n , -1 );
        cout<<minOp( 0 , a , dp )<<endl;

    }
}