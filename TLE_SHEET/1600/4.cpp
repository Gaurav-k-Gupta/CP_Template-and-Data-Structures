#include<bits/stdc++.h>
using namespace std;

#define ll long long



ll f( ll i , ll x , vector<ll>& a ){
    if( i == a.size() ){
        return 1e9;
    }
    if( a[i] >= x ) return 0;
    else{
        ll nxt = f( i + 1 , x - 1 , a );
        if( nxt == 1e9 ) return 1e9;
        return ( x - a[i] ) + nxt; 
    }
}

bool check( ll x , vector<ll>& a , ll k ){
    ll n = a.size();
    ll mini = 1e9;
    for(int i = 0 ; i < n ; i++){
        mini = min( mini , f(i , x , a));
    }
    if( mini <= k ) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        ll n , k ;
        cin>>n>>k;

        vector<ll> a(n);
        for(int i = 0 ; i < n ; i++ ) cin>>a[i];

        ll low = 0 , high = *max_element(a.begin() , a.end()) + k;
        while( low <= high ){
            ll mid = ( low + high ) / 2;
            if( check( mid , a , k )) low = mid + 1;
            else high = mid - 1;
        }

        cout<<high<<endl;
    }
}