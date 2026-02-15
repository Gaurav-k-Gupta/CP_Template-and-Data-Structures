#include<bits/stdc++.h>
using namespace std;

#define ll long long


void help( ll i , ll j , ll v , vector<ll>& b ){
    ll bi = b[i];
    ll bj = b[j];
    
    for(ll b = 0 ; b <= 32 ; b++){
        if( ( 1 << b ) & v ){
            bi |= ( 1 << b );
            bj |= ( 1 << b );
        }
    }

    b[i] = bi;
    b[j] = bj;
}


int main(){
    
    ll n;
    cin>>n;

    vector<vector<ll>> a( n , vector<ll>( n ));
    vector<ll> b( n , 0 );

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < n ; j++){
            cin>>a[i][j];
            if( i == j ) continue;
            help(i , j , a[i][j] , b);
        }
    }


    
    for(auto it : b){
        cout<<it<<" ";
    }

    cout<<endl;
    

}