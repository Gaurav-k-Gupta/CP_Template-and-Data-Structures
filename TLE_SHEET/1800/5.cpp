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
#define ppi pair<int,pair<int,int>>
#define ppll pair<ll,pair<ll,ll>>
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define loop(i,n,d) for(int i=0 ; i<n ; i += d)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(a) (a).begin() , (a).end()
#define prt(a) cout<<a<<endl

const ll mod = 1e9+7;
const ll INF = 1e9;



// Right now, this segment tree is for quering max element in a range, point update ( replace ) , range update ( addend ) , do some little changes according to the queries or updates you want and then use it.
class seg_tree{
    private:

    int n;
    vll t;
    vll lazy;


    ll combine( ll a , ll b ){
        return a+b;
    }

    void buildHelper( int v , int tl , int tr , vll & a){
        if (tl == tr) {
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr) / 2;
            buildHelper(v*2 , tl , tm , a);
            buildHelper( v*2 + 1 , tm+1 , tr , a );
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    void push(int v){
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];

        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];

        lazy[v] = 0;
    }

    void pointUpdateHelper( int v , int tl , int tr , int pos , int val ){
        if( tl == tr ){
            t[v] = val;
        }
        else{
            int tm = ( tl + tr )/2;
            if( pos <= tm ) pointUpdateHelper( v*2 , tl , tm , pos , val );
            else pointUpdateHelper( v*2 + 1 , tm+1 , tr , pos , val );

            t[v] = combine( t[v*2] , t[v*2 + 1]);
        }
    }

    void rangeUpdateHelper( int v , int tl , int tr , int l , int r , int addend ){
        if( l > r ) return;
        if( tl == tr ){
            t[v] += addend;
        }
        else{
            push(v);
            int tm = ( tl + tr )/2;
            rangeUpdateHelper(v*2 , tl , tm , l , min(r , tm) , addend);
            rangeUpdateHelper(v*2+1 , tm+1 , tr , max( tm+1 , l ) , r , addend);
            t[v] = combine( t[v*2] , t[v*2 + 1] );
        }
    }

    ll rangeQueryHelper( int v , int tl , int tr , int l , int r ){
        if( l > r ) return 0;
        if( l == tl && r == tr ) return t[v];
        push(v);
        int tm = ( tl + tr )/2;
        return combine(rangeQueryHelper( v*2 , tl , tm , l , min( tm , r ) ) , rangeQueryHelper( v*2 + 1 , tm+1 , tr , max( tm+1 , l ) , r));
    }

    public:

    seg_tree( vll &a ){
        this->n = a.size();
        t.resize( 4*n + 1 );
        lazy.resize( 4*n+1 , 0 );
        buildHelper( 1 , 0 , n-1 , a );
    }

    void pointUpdate( int pos , int val ){
        pointUpdateHelper( 1 , 0 , n-1 , pos , val );
    }

    void rangeUpdate( int l , int r , int val ){
        rangeUpdateHelper( 1 , 0 , n-1 , l , r , val );
    }

    ll rangeQuery( int l , int r ){
        return rangeQueryHelper( 1 , 0 , n-1 , l , r );
    }
        
};






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




ll modPow( ll x , ll exp ){
    ll ans = 1;
    while( exp > 0 ){
        if( exp & 1 ) ans = ans * x % mod;
        x = x*x % mod;
        exp /= 2;
    }
    return ans;
}


ll Pow( ll x , ll exp ){
    ll ans = 1;
    while( exp > 0 ){
        if( exp & 1 ) ans = ans * x;
        x = x*x;
        exp /= 2;
    }
    return ans;
}


ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll lcm( ll a , ll b ){
    ll x = 0 , y = 0;
    return a*b / gcd( a , b , x , y );
}



ll factorial[500000] = {0};
ll fact_inv[500000] = {0};

ll fact( ll n ){
    if( !n ) return 1LL;
    if( factorial[n] ) return factorial[n];
    return factorial[n] = ( n * fact(n-1) ) % mod ;
}

ll mod_inv( ll n ){
    if( fact_inv[n] ) return fact_inv[n];
    return fact_inv[n] = modPow( fact(n) , mod - 2 ) % mod;
}

ll ncr(ll n , ll r){
    return ( fact(n) * mod_inv(r) % mod * mod_inv(n-r) % mod ) % mod ;
}



class disjoint_set{
    private:
    vector<int> par;
    vector<int> rank;
    vector<int> size;

    public:
    disjoint_set(int size){
        par.resize(size+1);
        rank.resize(size+1,0);
        this->size.resize(size+1,1);
        for(int i=0 ; i<=size ; i++) par[i] = i;
    }

    int Find(int X)
    {
       if(X==par[X]) return X;
       return par[X] = Find(par[X]);
    }

    void Union(int x,int z)
    {
        int ulp_x = Find(x);
        int ulp_z = Find(z);
        if(ulp_x == ulp_z ) return;
        if(rank[ulp_x] > rank[ulp_z]){
            par[ulp_z] = ulp_x;
            size[ulp_x] += size[ulp_z];
        }
        else if(rank[ulp_x] < rank[ulp_z]){
            par[ulp_x] = ulp_z;
            size[ulp_z] += size[ulp_x];
        }
        else{
            par[ulp_x] = ulp_z;
            rank[ulp_z]++;
            size[ulp_z] += size[ulp_x];
        }
    }

    int Size(int x){
        int ulp_x = Find(x);
        return this->size[ulp_x];
    }
};


struct Fenwick {
  int N;
  vector<long long> f;
  Fenwick(int n):N(n),f(n+1,0){}
  // add v at index i
  void add(int i, long long v){
    for(++i; i<=N; i+=i&-i)
      f[i] += v;
  }
  // prefix sum [0..i]
  long long sum(int i){
    long long s = 0;
    for(++i; i>0; i-=i&-i)
      s += f[i];
    return s;
  }
};




// ll minTime( ll node , ll prevCycle , vector<vector<pll>>& adj , vll & s , vector<vll>& dp ){
//     ll n = adj.size();

//     if( node == n-1 ) return 0;

//     if( dp[node][prevCycle] != -1 ) return dp[node][prevCycle];

//     cout<<node<<endl;

//     ll mini = 1e12;
//     for(auto & it : adj[node]){
//         ll v = it.first;
//         ll w = it.second;
        
//         ll pick = ( s[node] * w ) + minTime( v , node , adj , s , dp );
        

//         ll nonPick = 1e12;
//         if( prevCycle < n ){
//             nonPick = ( s[prevCycle] * w ) + minTime( v , prevCycle , adj , s , dp );
//         }

//         mini = min( mini , min( pick , nonPick ));
//     }

//     return dp[node][prevCycle] = mini;
// }



vll dij( ll node , vector<vector<pll>>& adj ){
    ll n = adj.size();

    vll dis(n , 1e12);
    dis[node] = 0;

    priority_queue< pll , vector<pll> , greater<pll> > pq;

    pq.push({ 0 , node });

    while( !pq.empty() ){
        
        ll d = pq.top().first;
        ll u = pq.top().second;
        
        pq.pop();

        
        if( d > dis[u] ) continue;

        for(auto & it : adj[u]){

            ll v = it.first;
            ll w = it.second;
            
            ll d_new = d + w;
        
            if( dis[v] > d_new ){
                dis[v] = d_new;
                pq.push({ d_new , v });
            }
        }
    }

    return dis;
}




void solve(){
    ll n , m;
    cin>>n>>m;

    vector<vector<pll>> adj(n);
    for(int i = 0 ; i < m ; i++){
        ll u , v , w;
        cin>>u>>v>>w;
        u--; v--;

        adj[u].push_back({ v , w });
        adj[v].push_back({ u , w });
    }

    vll s(n);
    for(int i = 0 ; i < n ; i++) cin>>s[i];


    
    // vll dis = dij( 0 , adj );

    // for(ll i = 0 ; i < n ; i++) dp[i][0] = dis[i] * s[0]; 

    // for( ll j = 1 ; j < n ; j++ ){
    //     for(ll i = 0 ; i < n ; i++){
            
    //         for( auto & it : adj[i] ){
    //             ll v = it.first;
    //             ll w = it.second;

    //             dp[v][j] = min( dp[v][j] , dp[i][j-1] + s[j-1] * w );
    //         }
        
    //     }
    // }

    // ll res = 1e12;
    // for(ll j = 0 ; j < n ; j++){
    //     res = min( res , dp[n-1][j] );
    // }

    // cout<<res<<endl;

    // ll res = minTime( 0 , n , adj , s , dp );

    // cout<<res<<endl;


    vector<vll> dp( n , vll( n+1 , 1e12 ));


    priority_queue< ppll , vector<ppll> , greater<ppll> > pq;
    pq.push({ 0 , { 0 , n }});

    while(!pq.empty()){
        ll ti = pq.top().first;
        ll city = pq.top().second.first;
        ll lastCycle = pq.top().second.second;

        pq.pop();

        if( dp[city][lastCycle] <= ti ) continue;

        dp[city][lastCycle] = ti;

        for(auto & it : adj[city]){
            ll v = it.first;
            ll w = it.second;

            ll pick = ti + s[city] * w;
            pq.push({ pick , { v , city }});

            if( lastCycle != n ){
                ll nonPick = ti + s[lastCycle] * w;
                pq.push({ nonPick , { v , lastCycle }});
            }
        }
    }

    ll ans = 1e12;
    for(auto & x : dp[n-1]){
        ans = min( ans , x );
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }
}