#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

void solve(){
    ll n , l , k;
    cin>>n>>l>>k;

    vll d(n) , a(n);
    for(int i = 0 ; i < n ; i++) cin>>d[i];
    for(int i = 0 ; i < n ; i++) cin>>a[i];

    d.push_back(l);


    // vector<vector<vll>> dp( n+1 , vector<vll>(k+1 , vll(n+1 , 1e14)));
    vector<vll> dpi( k+1 , vll(n , 1e14));
    vector<vll> dpip1( k+1 , vll(n , 0));

    // for(ll t = 0 ; t <= k ; t++){
    //     for(ll prev = 0 ; prev < n ; prev++) dpip1[t][prev] = 0;
    // }

    for(ll i = n-1 ; i >= 1 ; i--){
        for(ll t = k ; t >= 0 ; t--){
            for(ll prev = n-1 ; prev >= 0 ; prev--){
                ll pick = ( d[i+1] - d[i] ) * ( a[i] ) + dpip1[t][i];
                ll nonPick = 1e14;
                if( t < k ) nonPick = ( d[i+1] - d[i] ) * ( a[prev] ) + dpip1[t+1][prev];

                dpi[t][prev] = min( pick , nonPick );
            }
        }

        dpip1 = dpi;
    }


    cout<<dpip1[0][0] + (d[1] - d[0]) * a[0]<<endl;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



    int t;
    t = 1;
    while( t-- ){
        solve();
    }
}