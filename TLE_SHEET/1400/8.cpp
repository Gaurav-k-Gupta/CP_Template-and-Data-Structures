#include<bits/stdc++.h>
using namespace std;

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

const ll mod = 1e9 + 7;
const ll INF = 1e9;


vector<bool> is_prime( ll N ){
    vector<bool> isPrime( N+1 , true );
    isPrime[0] = isPrime[1] = false;
    for(int i=2 ; i*i <= N ; i++){
        if( isPrime[i] ){
            int j = i*i;
            while( j <= N ){
                isPrime[j] = false;
                j += i;
            }
        }
    }
    return isPrime;
}

vector<ll> primes( ll N ){
    vector<bool> isPrime = is_prime(N);
    vector<ll> Primes;
    for(ll i = 2 ; i <= N ; i++){
        if( isPrime[i] ) Primes.push_back(i); 
    }
    return Primes;
}



void dfs(int node , int pr , vector<vector<int>>& adj , vector<int>& par){
    par[node] = pr;
    for(auto it : adj[node]){
        if( pr == it ) continue;
        dfs( it , node , adj , par );
    }
    return;
}

int ans = 0;

void updateDp(int node , int pr , vector<vector<int>>& adj , vector<int>& dp , vector<int>& parUppar){
    if( pr == -1 ) dp[node] = 1;
    else{
        if( parUppar[node] ) dp[node] = min( dp[node] , dp[pr] );
        else dp[node] = min( dp[node] , dp[pr] + 1 );
    }

    ans = max( ans , dp[node] );

    for(auto it : adj[node]){
        if( it == pr ) continue;
        updateDp( it , node , adj , dp , parUppar );
    }

    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> adj(n);

        vector<int> vis(n , 0);
        vector<int> parUppar( n , 0 );

        vis[0] = 1;
        parUppar[0] = 1;

        vector<pair<int,int>> edges;

        for(int i = 0 ; i < n-1 ; i++){
            int u , v;
            cin>>u>>v;

            u--;
            v--;

            edges.push_back( {u , v} );

            adj[u].push_back(v);
            adj[v].push_back(u);

        }


        vector<int> par(n , -1);
        dfs(0 , -1 , adj , par);



        for(auto it : edges){
            int u = it.first;
            int v = it.second;

            if( par[u] == v ) swap(u,v);

            if( vis[u] ) parUppar[v] = 1;
            else parUppar[v] = 0;

            vis[v] = 1;

        }


        // for(auto it : parUppar){
        //     cout<<it<<" ";
        // }
        // cout<<endl;


        vector<int> dp(n , INF);
        dp[0] = 1;
        updateDp(0 , -1 , adj , dp , parUppar);

        cout<<ans<<endl;
        ans = 0;
    }


}