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


// bool check(vll& a , vll& b , int i ){
//     // i-1 , i , i+1
//     if( i == 0 || i == a.size() - 1 ){
//         return true;
//     }

//     ll g = gcd(a[i-1] , a[i+1]);

//     if( )
// }





class disjoint_set{
    private:
    vector<int> par;
    vector<int> rank;
    public:
    disjoint_set(int size){
        par.resize(size+1);
        rank.resize(size+1,0);
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
        }
        else if(rank[ulp_x] < rank[ulp_z]){
            par[ulp_x] = ulp_z;
        }
        else{
            par[ulp_x] = ulp_z;
            rank[ulp_z]++;
        }
    }
};




void solve(){
    ll n , m , k;
    cin>>n>>m>>k;

    vll a(n) , b(m);
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < m ; i++) cin>>b[i];

    map<ll,ll> mp1 , mp2;
    
    ll prev = 0;
    while( prev < n && !a[prev] ) prev++;

    for(int i = prev ; i < n ; i++){
        if( a[i] == 0 ){
            // mp1[1]++;
            // mp1[i-prev+1]--;

            prev = i+1;
            while( prev < n && !a[prev] ) prev++;
            i = prev-1;        
        }
        else{
            mp1[1]++;
            mp1[i-prev+2]--;
        }
    }

    // if( prev < n ){
    //     mp1[1]++;
    //     mp1[n-prev+1]--;
    // }

    prev = 0;
    while( prev < m && !b[prev] ) prev++;

    for(int i = prev ; i < m ; i++){
        if( b[i] == 0 ){
            // mp2[1]++;
            // mp2[i-prev+1]--;

            prev = i+1;
            while( prev < m && !b[prev] ) prev++;
            i = prev-1;        
        }
        else{
            mp2[1]++;
            mp2[i-prev+2]--;
        }
    }

    // if( prev < m ){
    //     mp2[1]++;
    //     mp2[m-prev+1]--;
    // }


    ll overlap = 0;
    for(auto &it : mp1){
        overlap += it.second;
        it.second = overlap;
        // cout<<it.first<<" "<<overlap<<endl;
    }

    // cout<<endl;

    overlap = 0;
    for(auto &it : mp2){
        overlap += it.second;
        it.second = overlap;

        // cout<<it.first<<" "<<overlap<<endl;
    }

    ll ans = 0;
    ll i = 1 , j = k;
    
    while( i*i <= k ){
        ans += mp1[i]*mp2[j];
        if( i != j ) ans += mp1[j]*mp2[i];
        // cout<<ans<<endl;
        // cout<<i<<" "<<j<<endl;
        // cout<<mp1[i]<<" "<<mp2[j]<<endl;
        i++;
        while( i*i <= k && k % i != 0 ) i++;
        j = k/i;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    while(t--){
        solve();
    }
}