#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        ll n , x , y;
        cin>>n>>x>>y;
        
        
        vector<ll> arr(n);
        
        for(int i = 0 ; i < n ; i++) cin>>arr[i];
        
        ll a = ( x % 2 );
        ll b = 1 - a;
        
        for(int i = 0 ; i < n ; i++){
            ll val = arr[i] % 2;
            
            a += val;
            b += val;
            
            a = a%2;
            b = b%2;
        }
        
        if( a == (y % 2) ) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}