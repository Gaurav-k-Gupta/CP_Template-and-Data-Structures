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

const ll mod = 1e9 + 7;
const ll INF = 1e9;



// Right now, this segment tree is for quering max element in a range, point update ( replace ) , range update ( addend ) , do some little changes according to the queries or updates you want and then use it.
class seg_tree{
    private:

    int n;
    vll t;
    vll lazy;


    ll combine( ll a , ll b ){
        return max(a,b);
    }

    void buildHelper( int v , int tl , int tr , vi & a){
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
            t[v] = combine( t[v*2] , t[v*2 + 1]);
        }
    }

    ll rangeQueryHelper( int v , int tl , int tr , int l , int r ){
        if( l > r ) return -INF;
        if( l == tl && r == tr ) return t[v];
        push(v);
        int tm = ( tl + tr )/2;
        return max(rangeQueryHelper( v*2 , tl , tm , l , min( tm , r ) ) , rangeQueryHelper( v*2 + 1 , tm+1 , tr , max( tm+1 , l ) , r));
    }

    public:

    seg_tree( vi &a ){
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


vector<vector<ll>> factors( ll N ){
    vector<vector<ll>> fac(N+1);

    for(ll i = 1 ; i <= N ; i++){
        ll v = i;
        while( v <= N ){
            fac[v].push_back(i);
            v += i;
        }
    }

    return fac;
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

vll pi_func( string & s ){
    ll n = s.size();
    vll pii(n);
    for(ll i = 1 ; i < n ; i++){
        ll j = pii[i-1];
        while( j && s[i] != s[j] ){
            j = pii[j-1];
        }
        if( s[i] == s[j] ) j++;
        pii[i] = j;
    }
    return pii;
}

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



void dfs( ll u , ll par , ll dis , vector<vll>& adj , vll & d ){
    d[u] = dis;

    for(auto it : adj[u]){
        if( it == par ) continue;

        dfs( it , u , dis+1 , adj , d );
    }

    return;
}

bool check( ll u , ll par , vector<vll>& adj , vll & d , unordered_set<ll>& st , ll mf ){

    unordered_map<ll,ll> mp;
    for(auto it : adj[u]){
        if( it == par ) continue;

        if( st.count(d[it]) ) mp[d[it]]++;

        if( check(it , u , adj , d , st , mf ) ) return true;
    }

    for(auto it : mp){
        if( it.second == mf ) return true;
    }

    return false;
}

void dfs2( ll u , ll par , vector<vll>& adj , vll & co , vll & d , vector<unordered_set<ll>> & col ){
    
    if( par != -1 ){
        ll dv = d[u];
        ll p1 = *col[dv].begin();
        if( co[par] == p1 ){
            yes;
            cout<<col[dv].size()<<endl;
            col[dv].erase(p1);
            ll p2 = *col[dv].begin();
            co[u] = p2;
            col[dv].erase(p2);
            col[dv].insert(p1);
        }
        else{
            co[u] = p1;
            col[dv].erase(p1);
        }
    }

    cout<<u<<": "<<co[u]<<endl;

    for(auto it : adj[u]){
        if( it == par ) continue;
        dfs2( it , u , adj , co , d , col );
    }

    return;
}


ll f( ll n , ll k , unordered_map<ll,ll>& mp ){
    if( n == k ) return 0;
    if( n < k ) return INF;

    if( mp.count(n) ) return mp[n];

    ll x = n/2;
    ll y = n - x;

    if( x == y ){
        ll v = f( x , k , mp );
        if( v != INF ) v++;
        return mp[n] = v;
    }
    else{
        ll v1 = f(x , k , mp);
        ll v2 = f(y , k , mp);
        if( v1 != INF ) v1++;
        if( v2 != INF ) v2++;
        return mp[n] = min( v1 , v2 );
    }
}



ll NCR( ll n , ll r ){
    if( r == 0 || r == n ) return 1;
    if( r > (n/2) ) return NCR( n , n-r );

    ll x = 1;
    ll v = n - r + 1;

    ll res = 1LL;

    while( v <= n && x <= r ){
        if( res % x == 0 ){
            res /= x;
            x++;
        }

        res *= v;
        v++;
    }

    // cout<<res<<endl;

    while( v <= n ){
        res *= v;
        v++;
    }
    while( x <= r ){
        res /= x;
        x++;
    }

    return res;
}


vector<pll> merge( ll l1 , ll r1 , ll l2 , ll r2 ){
            vector<pll> tmp;
            if( l1 < l2 ){
                if( l2 > r1 ){
                    tmp.push_back({l1 , r1});
                    tmp.push_back({l2 , r2});
                }
                else{
                    tmp.push_back({l1 , max(r1,r2)});
                }
            }
            else{
                if( l1 > r2 ){
                    tmp.push_back({l2 , r2});
                    tmp.push_back({l1 , r1});
                }
                else{
                    tmp.push_back({l2 , max(r1,r2)});
                }
            }

            return tmp;
}

// vector<pll> merge_3( pll a , pll b , pll c ){
//     if( )
// }


void solve(){

    ll n;
    cin>>n;

    vll a(n);
    for(ll i = 0 ; i < n ; i++) cin>>a[i];

    vector<vector<pll>> rg(n);

    ll pd = abs(a[1] - a[0]);
    ll pid = 0;
    for(ll i = 1 ; i < n ; i++){
        // cout<<i<<endl;
        ll d = abs(a[i] - a[i-1]);
        if( pd != d ){
            // yes;
            rg[pd].push_back({ pid , i-1 });
            pid = i-1;
        }
        pd = d;
    }

    rg[pd].push_back({pid , n-1});

    // for(ll k = 0 ; k < n ; k++){
    //     cout<<k<<endl;
    //     for(auto it : rg[k]){
    //         cout<<it.first<<" "<<it.second<<endl;
    //     }
    // }

    

    vector<pll> cur;
    vll res(n , 0);

    ll k = n-1;
    while( k > 0 ){

        if( rg[k].empty() ){
            if( k < n-1 ) res[k] = res[k+1];
            k--;
            continue;
        }

        ll s1 = rg[k].size();
        ll s2 = cur.size();

        ll i = 0 , j = 0;
        vector<pll> tmp;
        // ll l = -1 , r = -1;
        while( i < s1 && j < s2 ){
            ll l1 = rg[k][i].first , r1 = rg[k][i].second;
            ll l2 = cur[j].first , r2 = cur[j].second;

            if( tmp.empty() ){
                vector<pll> mg = merge(l1 , r1 , l2 , r2);
                for(auto it : mg) tmp.push_back(it);
            }
            else{
                pll p = tmp.back();

                if( l1 < l2 ){
                    vector<pll> mg = merge( p.first , p.second , l1 , r1 );
                    if( mg.size() == 1 ){

                    }
                    else{
                        
                    }
                }
                else{
                    vector<pll> mg = merge( p.first , p.second , l2 , r2 );
                }
            }
        }

        while( i < s1 ) tmp.push_back(rg[k][i++]);
        while( j < s2 ) tmp.push_back(cur[j++]);

        // if( cur.empty() ){
        //     k--;
        //     continue;
        // }

        // sort(cur.begin() , cur.end());

        ll cnt = 0;
        // vector<pll> ncur;
        // ll l = cur[0].first , r = cur[0].second;

        // cout<<k<<endl;
        cout<<k<<" , "<<endl;
        for(auto it : tmp){
            ll L = it.first;
            ll R = it.second;
            cout<<L<<" "<<R<<endl;
            // cout<<L<<" "<<R<<endl;

            ll el = R - L + 1;
            cnt += (el * (el-1)) / 2;

            // if( L > r ){
            //     ncur.push_back({ l , r });

            //     ll el = r - l + 1;
            //     cnt += (el * (el-1)) / 2;

            //     l = L;
            //     r = R;
                
            // }

            // r = max( r , R );
        }

        // ll el = r - l + 1;
        // cnt += ( el * (el-1) ) / 2;
        // ncur.push_back({ l , r });

        res[k] = cnt;
        cur = tmp;
        k--;
    }
    

    for(ll k = 1 ; k < n ; k++) cout<<res[k]<<" ";
    cout<<endl;
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