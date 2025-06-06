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

const ll mod = 1e9 + 7;
const ll INF = 1e14;



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


ll gcd( ll a , ll b ){
    return b ? gcd( b , a%b ) : a;
}

ll lcm(ll a , ll b){
    ll g = gcd(a,b);
    return (a*b)/g;
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



void solve(){

    ll n , k;
    cin>>n>>k;

    vector<vector<pll>> dp( k+1 , vector<pll>(n+1 , {0,0}));

    dp[k][0].second = 1;
    dp[k][0].first = 0;
    
    ll cnt = 1;

    for(ll age = k-1 ; age >= 1 ; age--){
        ll sum = dp[age+1][0].second;
        for(ll m = 1 ; m <= n ; m++){
            dp[age][m].first = sum;
            cnt = ( cnt + sum ) % mod;
            sum = (sum + dp[age+1][m].second) % mod;
        }

        sum = 0;
        for(ll m = n ; m >= 1 ; m--){
            dp[age][m].second = sum;
            cnt = ( cnt + sum ) % mod ;
            sum = ( sum + dp[age+1][m].first ) % mod;
        }
    }


    cout<<cnt<<endl;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}