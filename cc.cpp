#include <bits/stdc++.h>
using namespace std;

#define ll long long

// f = 1 => not cut yet

ll fn( ll i , ll j , ll f , string &a , string &b , vector<vector<vector<ll>>> & dp){
    ll n = a.size();
    ll m = b.size();
    
    if( i >= n ){
        if( j >= m ) return 0;
        else return 1e9;
    }
    else if( j >= m ){
        return 1;
    }
    
    if( dp[i][j][f] != -1 ) return dp[i][j][f];
        
    if( f ){
        ll p = 1e9;
        if( a[i] == b[j] ) p = fn( i+1 , j+1 , 1 , a , b , dp );
        
        ll np = fn( i+1 , j , 0 , a , b , dp );
        if( np != 1e9 ) np++;
        
        return dp[i][j][f] = min( p , np );
    }
    else{
        ll p = 1e9;
        if( a[i] == b[j] ) p = fn( i+1 , j+1 , 1 , a , b , dp );
        
        ll np = fn( i+1 , j , 0 , a , b , dp );
        
        return dp[i][j][f] = min( p , np );   
    }
}



int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        string a,b;
        cin>>a>>b;
        
        vector<vector<vector<ll>>> dp( n+1 , vector<vector<ll>>( m+1 , vector<ll>( 2 , 1e9 )));

        dp[n][m][0] = dp[n][m][1] = 0;
        for(ll i = 0 ; i < n ; i++){
            dp[i][m][0] = dp[i][m][1] = 1;
        }

        for(ll i = n-1 ; i >= 0 ; i--){
            for(ll j = m-1 ; j >= 0 ; j--){
                for(ll f = 0 ; f <= 1 ; f++){
                    if( f ){
                        ll p = 1e9;
                        if( a[i] == b[j] ) p = dp[i+1][j+1][1];
                        
                        ll np = dp[i+1][j][0];
                        if( np != 1e9 ) np++;
                        
                        dp[i][j][f] = min( p , np );
                    }
                    else{
                        ll p = 1e9;
                        if( a[i] == b[j] ) p = dp[i+1][j+1][1];
                        
                        ll np = dp[i+1][j][0];
                        
                        dp[i][j][f] = min( p , np );   
                    }
                }
            }
        }
        
        ll res = dp[0][0][1];
        
        if( res == 1e9 ) cout<<-1<<endl;
        else cout<<res<<endl;
    }
}
