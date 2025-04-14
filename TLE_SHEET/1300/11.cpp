#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll cnt = 0;
ll dfs( int node , int par , vector<vector<int>>& adj , string& s ){

    ll diff = s[node] == 'W' ? 1LL : -1;

    for(auto it : adj[node]){
        if( it == par ) continue;
        diff += dfs( it , node , adj , s );
    }

    if( !diff ) cnt++;

    return diff;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> adj(n);
        for(int i = 2 ; i <= n ; i++){
            int p;
            cin>>p;

            adj[p-1].push_back(i-1);
            adj[i-1].push_back(p-1);
        }


        string col;
        cin>>col;

        cnt = 0;
        ll res = dfs( 0 , -1 , adj , col );
        
        cout<<cnt<<endl;
    }
    return 0;
}