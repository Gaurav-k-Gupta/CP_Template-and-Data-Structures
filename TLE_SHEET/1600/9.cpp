#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(vector<vector<ll>> & dp){
    ll n;
    cin>>n;

    vector<ll> rows(2024 , 0);
    iota(rows.begin() + 1 , rows.end() , 1 );

    ll low = 1 , high = 2023;
    while( low <= high ){
        ll mid = ( low + high ) / 2;
        ll val = mid*(mid+1) / 2;
        if( val >= n ) high = mid - 1;
        else low = mid + 1;
    }

    ll r = low;
    ll c = n - (r-1)*(r)/2; 


    ll cnt = dp[r][c];

    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> dp(2024);
    for(int i = 1 ; i <= 2023 ; i++){
        dp[i].resize(i+1 , 0);
        if( i == 1 ) dp[1][1] = 1;
        else{
            ll val1 = ((i-1)*(i)/2 + 1);
            ll val2 = ((i-1)*(i)/2 + i);
            dp[i][1] =  val1*val1 + dp[i-1][1];
            dp[i][i] = val2*val2 + dp[i-1][i-1];
            
            for(int c = 2 ; c <= i-1 ; c++){
                ll val = ((i-1)*(i)/2 + c);
                dp[i][c] = val*val + dp[i-1][c-1] + dp[i-1][c];

                if( i > 2 ){
                    dp[i][c] -= dp[i-2][c-1];
                }
            }
        }
    }

    int T;
    cin >> T;
    while(T--){
        solve(dp);
    }
    return 0;
}
