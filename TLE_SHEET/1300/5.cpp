#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n = s.size();

        int curr = s[0] - '0';
        ll cnt = 0;
        ll ans1 = 0 , ans2 = 1;


        for(int i = 0 ; i < n ; i++){
            if( curr == s[i] - '0' ){
                cnt++;
            }
            else{
                // cout<<i<<" "<<cnt<<endl;
                ans2 = ( ans2 * cnt ) % MOD;
                ans1 += cnt - 1;
                cnt = 1;
                curr = s[i] - '0';
            }
        }
        ans2 = ( ans2 * cnt ) % MOD;
        ans1 += cnt - 1;
        for(ll i = 1 ; i <= ans1 ; i++){
            ans2 = ( ans2 * i ) % MOD;
        }

        cout<<ans1<<" "<<ans2<<endl;
    }
}