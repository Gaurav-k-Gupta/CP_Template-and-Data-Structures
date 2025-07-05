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

bool chq;

ll dfs( ll u , ll par , char m , vector<vector<pair<ll,char>>>& adj , vll & vis ){
    
    if( vis[u] ){
        if( (vis[u] == 2 && m == 'I') || (vis[u] == 1 && m == 'C') ) chq = false;
        return 0;
    }

    ll cnt = 0;
    if( m == 'I' ) cnt++;
    // I -> 1 , C -> 2
    vis[u] = 1;
    if( m == 'C' ) vis[u] = 2;
    
    for(auto & it : adj[u]){
        if( it.first == par ) continue;
        char nxt_m = it.second;
        if( m == 'I' ){
            if( it.second == 'I' ) nxt_m = 'C';
            else nxt_m = 'I';
        }

        cnt += dfs( it.first , u , nxt_m , adj , vis );
    }

    return cnt;
}



void solve(){
    ll n , m;
    cin>>n>>m;

    chq = true;
    vector<vector<pair<ll,char>>> adj( n+1 );
    unordered_map<ll,ll> mpC;
    unordered_map<ll,ll> mpI;

    bool check = true;

    for(int i = 0 ; i < m ; i++){
        ll u , v ;
        string c;
        cin>>u>>v>>c;
        char msg;
        if( c == "imposter" ) msg = 'I';
        else msg = 'C';
        adj[u].push_back({ v , msg });
        adj[v].push_back({ u , msg });

        ll hash = u * n + v ;
        ll rev_hash = v * n + u;
        if( msg == 'I' && ( mpC[hash] || mpC[rev_hash] ) ){
            check = false;
            mpI[hash] = 1;
            mpI[rev_hash] = 1;
        }
        if( msg == 'C' && ( mpI[hash] || mpI[rev_hash] ) ){
            check = false;
            mpC[hash] = 1;
            mpC[rev_hash] = 1;
        }



        if( msg == 'I' ){
            mpI[hash] = 1;
            mpI[rev_hash] = 1;
        }
        if( msg == 'C' ){
            mpC[hash] = 1;
            mpC[rev_hash] = 1;
        }
        
    }

    if( !check ){
        cout<<-1<<endl;
        return;
    }


    ll cnt = 0;
    vll vis1( n+1 , 0 );
    vll vis2( n+1 , 0 );
    for(ll i = 1 ; i <= n ; i++){
        if( vis1[i] ) continue;
        ll res1 = dfs(i , -1 , 'I' , adj , vis1);
        ll res2 = dfs(i , -1 , 'C' , adj , vis2);
        cnt += max(res1 , res2);
    }
    if( !chq ){
        cout<<-1<<endl;
    }
    else cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // vector<bool> isP = is_prime(1e5+1);
    // vll pms = primes(1e5 + 1);


    int t;
    cin>>t;
    // t = 1;
    while( t-- ){
        solve();
    }
}