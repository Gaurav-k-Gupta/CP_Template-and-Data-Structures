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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vll a(n);
        for(int i=0 ; i<n ; i++) cin>>a[i];

        string s;
        cin>>s;

        ll x0 = 0 , x1 = 0;

        vll dp(n , 0);
        dp[0] = a[0];
        for(int i=0 ; i<n ; i++){
            if( s[i] == '1' ){
                x1 ^= a[i];
            }
            else{
                x0 ^= a[i];
            }
            if( i ) dp[i] = dp[i-1]^a[i];
        }


        ll q;
        cin>>q;
        while(q--){
            ll f;
            cin>>f;

            if( f == 1 ){
                ll l , r;
                cin>>l>>r;

                ll range_xor = dp[r-1];
                if( l > 1 ) range_xor ^= dp[l-2];

                x0 ^= range_xor;
                x1 ^= range_xor;


            }
            else{
                ll g;
                cin>>g;

                if( g ) cout<<x1<<" ";
                else cout<<x0<<" ";
            }
        }

        cout<<endl;
    }
}