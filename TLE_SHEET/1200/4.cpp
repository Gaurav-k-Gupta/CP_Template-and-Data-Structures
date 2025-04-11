#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll N = n*(n-1)/2;
        vector<ll> a(N);
        for(ll i=0 ; i<N ; i++) cin>>a[i];

        sort(a.begin() , a.end() );

        ll i = 0;
        ll adder = n-1;
        while( i < N ){
            cout<<a[i]<<" ";
            i += adder;
            adder--;
        }
        cout<<(a[N-1])<<endl;
    }
}