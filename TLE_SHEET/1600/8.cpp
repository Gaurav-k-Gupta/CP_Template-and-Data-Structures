#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(m);
    
    for(int i = 0 ; i < m ; i++){
        cin>>a[i];
    }

    sort(a.begin() , a.end());

    ll cnt = 0;
    
    for(int k = 1 ; k < n ; k++){
        ll req1 = k;
        ll req2 = n - k;

        ll cnt1 = a.end() - lower_bound(a.begin() , a.end() , req1);
        ll cnt2 = a.end() - lower_bound(a.begin() , a.end() , req2);


        cnt += cnt1*cnt2 - min(cnt1,cnt2);

    }

    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
