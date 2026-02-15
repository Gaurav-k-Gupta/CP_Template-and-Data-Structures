#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll val( vector<ll> & v1 , vector<ll>& v2 ){
    
    ll s = 0;
    for(ll i = 0 ; i < 5 ; i++){
        s += v1[i]*v2[i];
    }

    if( s <= 0 ) return 0;
    return 1;
}



ll help( ll i , ll j , ll k , vector<vector<ll>>& a ){
    vector<ll> v1( 5 ) , v2( 5 );

    for(ll p = 0 ; p < 5 ; p++){
        v1[p] = a[j][p] - a[i][p];
        v2[p] = a[k][p] - a[i][p];
    }

    return val( v1 , v2 );
}


int main(){
    
    ll n;
    cin>>n;

    vector<vector<ll>> a( n , vector<ll>( 5 ));
    // vector<ll> b( n , 0 );

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < 5 ; j++){
            cin>>a[i][j];
        }
    }


    if( n > 100 ){
        cout<<0<<endl;
        return 0;
    }
    
    vector<ll> res;
    for(ll i = 0 ; i < n ; i++){
        
        ll good = 1;

        for(ll j = 0 ; j < n ; j++){
            if( j == i ) continue;
            for(ll k = 0 ; k < n ; k++){
                if( k == j || k == i ) continue;

                ll v = help( i , j , k , a );
                // cout<<i<<" "<<j<<" "<<k<<endl;
                // cout<<v<<endl;
                if( v ) good = 0;
            }
        }

        if( good ) res.push_back( i+1 );
    }


    cout<<res.size()<<endl;
    for(auto it : res) cout<<it<<" ";
    cout<<endl;
}