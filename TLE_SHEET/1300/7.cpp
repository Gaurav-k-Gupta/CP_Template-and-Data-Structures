#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    vector<ll> dp( 1e6+1 , 0 );
    ll k = 2;
    while( k < 1e6 ){
        ll start = 1 + k + k*k;
        ll mul = k*k*k;

        while( start <= 1e6 ){
            dp[start] = 1;
            start += mul;
            mul *= k;
        }
        k++;
    }

    while(t--){
        ll n;
        cin>>n;

        if( dp[n] ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}