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
#define vpi vector<pi>
#define vpll vector<pll>
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
    vpll t;
    vll lazy;

    // <idx , val>
    pll combine( pll a , pll b , int tr1 ){
        if( a.first == b.first && a.first == -1 ){
            if( a.second != b.second ) return { tr1 , -1 };
            else return { -1 , a.second };
        }

        if(a.first != -1 ) return a;
        return b;
    }

    void buildHelper( int v , int tl , int tr , vi & a){
        if (tl == tr) {
            t[v].first = -1;
            t[v].second = a[tl];
        }
        else{
            int tm = (tl + tr) / 2;
            buildHelper(v*2 , tl , tm , a);
            buildHelper( v*2 + 1 , tm+1 , tr , a );
            t[v] = combine(t[v*2], t[v*2+1] , tm );
        }
    }

    // void push(int v){
    //     t[v*2] += lazy[v];
    //     lazy[v*2] += lazy[v];

    //     t[v*2+1] += lazy[v];
    //     lazy[v*2+1] += lazy[v];

    //     lazy[v] = 0;
    // }

    // void pointUpdateHelper( int v , int tl , int tr , int pos , int val ){
    //     if( tl == tr ){
    //         t[v] = val;
    //     }
    //     else{
    //         int tm = ( tl + tr )/2;
    //         if( pos <= tm ) pointUpdateHelper( v*2 , tl , tm , pos , val );
    //         else pointUpdateHelper( v*2 + 1 , tm+1 , tr , pos , val );

    //         t[v] = combine( t[v*2] , t[v*2 + 1]);
    //     }
    // }

    // void rangeUpdateHelper( int v , int tl , int tr , int l , int r , int addend ){
    //     if( l > r ) return;
    //     if( tl == tr ){
    //         t[v] += addend;
    //     }
    //     else{
    //         push(v);
    //         int tm = ( tl + tr )/2;
    //         rangeUpdateHelper(v*2 , tl , tm , l , min(r , tm) , addend);
    //         rangeUpdateHelper(v*2+1 , tm+1 , tr , max( tm+1 , l ) , r , addend);
    //         t[v] = combine( t[v*2] , t[v*2 + 1]);
    //     }
    // }

    pll rangeQueryHelper( int v , int tl , int tr , int l , int r ){
        if( l > r ) return { -INF , -INF };
        if( l == tl && r == tr ) return t[v];
        // push(v);
        int tm = ( tl + tr )/2;

        pll lft = rangeQueryHelper( v*2 , tl , tm , l , min( tm , r ));
        pll rt = rangeQueryHelper( v*2 + 1 , tm+1 , tr , max( tm+1 , l ) , r);
        
        if( lft.first == -INF ) return rt;
        else if( rt.second == -INF ) return lft;
        else return combine( lft , rt , tm );
    }

    public:

    seg_tree( vi &a ){
        this->n = a.size();
        t.resize( 4*n + 1 );
        lazy.resize( 4*n+1 , 0 );
        buildHelper( 1 , 0 , n-1 , a );
        // for(auto it : t) cout<<it.first<<" "<<it.second<<endl;
    }

    // void pointUpdate( int pos , int val ){
    //     pointUpdateHelper( 1 , 0 , n-1 , pos , val );
    // }

    // void rangeUpdate( int l , int r , int val ){
    //     rangeUpdateHelper( 1 , 0 , n-1 , l , r , val );
    // }

    pll rangeQuery( int l , int r ){
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






void solve(){

    int n;
    cin>>n;

    vi a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    seg_tree t(a);

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;

        pll res = t.rangeQuery(l-1 , r-1);
        if( res.first == -1 ) cout<<"-1 -1"<<endl;
        else cout<<res.first+1<<" "<<res.first + 2<<endl;
    }

    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while( t-- ){
        solve();
    }
}