#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>

ll maxCnt( int idx , int prev1 , int prev2 , int prev3 , vll &a , vll & b , vll & c , vector<vector<vector<vll>>> & dp){
    if( idx == a.size() || (prev1 && prev2 && prev3) ) return 0;

    if( dp[idx][prev1][prev2][prev3] != -1 ) return dp[idx][prev1][prev2][prev3];
    ll cnt = 0;
    if( !prev1 ) cnt = max(a[idx] + maxCnt( idx+1 , 1 , prev2 , prev3 , a , b , c , dp) , cnt);
    if( !prev2 ) cnt = max(b[idx] + maxCnt( idx+1 , prev1 , 1 , prev3 , a , b , c , dp) , cnt);
    if( !prev3 ) cnt = max( c[idx] + maxCnt( idx+1 , prev1 , prev2 , 1 , a , b , c , dp) , cnt);
    cnt = max( maxCnt( idx+1 , prev1 , prev2 , prev3 , a , b , c , dp ) , cnt);

    return dp[idx][prev1][prev2][prev3] = cnt;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vll a(n) , b(n) , c(n);


        for(int i=0 ; i<n ; i++) cin>>a[i];
        for(int i=0 ; i<n ; i++) cin>>b[i];
        for(int i=0 ; i<n ; i++) cin>>c[i];

        vector<vector<vector<vll>>>  dp( n , vector<vector<vll>>( 2 , vector<vll>(2 , vll( 2, -1))));

        ll ans = maxCnt( 0 , 0 , 0 , 0 , a , b , c , dp);
        cout<<ans<<endl;

    }
}