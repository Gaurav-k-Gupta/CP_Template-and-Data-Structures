#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<ll> a(n);
        map<ll,ll> mp;
        bool ans = false;
        mp[0] = 1;
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
            if( i & 1 ) a[i] = -a[i];
            if( i > 0 ) a[i] += a[i-1];
            if( mp[a[i]] ) ans = true;
            mp[a[i]] = 1;
        }

        if( ans ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}