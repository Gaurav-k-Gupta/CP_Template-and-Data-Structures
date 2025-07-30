/*
Author :- Gaurav Kumar
Date - 30/03/2025
*/

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;



// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pair<int,int>>
#define ppll pair<pair<ll,ll>>
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define loop(i,n,d) for(int i=0 ; i<n ; i += d)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(a) (a).begin() , (a).end()
#define prt(a) cout<<a<<endl

// const ll mod = 1e9+7;
// const ll INF = 1e9;


void dfs( int v , int par , vector<vector<pi>>& adj , vi & a , vector<map<int,ll>> & dp , vector<pi> & parent ){

    for(auto & it : adj[v]){
        int u = it.first;
        int w = it.second;

        if( u == par ){
            parent[v] = { u , w };
            continue;
        }

        dfs( u , v , adj , a , dp , parent );

        dp[v][a[u]] += w;
    }


    return;
}




void solve(){
    int n , q;
    cin>>n>>q;

    vi a(n);
    for(int i = 0 ; i < n ; i++) cin>>a[i];

    vector<vector<pi>> adj(n);
    for(int i = 0 ; i < n - 1 ; i++){
        int u , v , c;
        cin>>u>>v>>c;
        u--; v--;
        adj[u].pb({v , c});
        adj[v].pb({u , c});
    }


    vector<map<int,ll>> dp(n);
    vector<pi> parent(n);


    dfs( 0 , -1 , adj , a , dp , parent );

    ll ans = 0;
    for(int i = 1 ; i < n ; i++){
        int u = parent[i].first;
        int w = parent[i].second;
        if( a[u] != a[i] ) ans += w;
    }

    while(q--){
        int v , x;
        cin>>v>>x;
        v--;


        int old = a[v];
        ans += dp[v][old];
        ans -= dp[v][x];

        if( v == 0 ){
            a[v] = x;
            cout<<ans<<endl;
            continue;
        }


        int par = parent[v].first;
        int w = parent[v].second;
        if( old != a[par] ) ans -= w;
        if( x != a[par] ) ans += w;


        dp[par][old] -= w;
        dp[par][x] += w;

        a[v] = x;

        cout<<ans<<endl;

    }
    

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    // t = 1;
    while( t-- ){
        solve();
    }

}