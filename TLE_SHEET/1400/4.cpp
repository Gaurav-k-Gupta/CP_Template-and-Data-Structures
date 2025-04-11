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
        ll n,k;
        cin>>n>>k;

        vll a(n);
        for(int i=0 ; i<n ; i++) cin>>a[i];

        sort(a.begin() , a.end());


        if( k == 1 ){
            ll ans = a[0];
            for(int i=1 ; i<n ; i++){
                ans = min( ans , a[i] - a[i-1] );
            }
            cout<<ans<<endl;
        }
        else if( k == 2 ){
            vector<ll> diff;
            for(int i=0 ; i<n ; i++){
                for(int j=i+1 ; j<n ; j++){
                    diff.push_back(a[j]-a[i]);
                }
            }

            ll ans = a[0];
            for(auto it : diff){
                ll val = it;
                ans = min( ans , val );
                int id1 = lower_bound( a.begin() , a.end() , val ) - a.begin();

                if( id1 < n ) ans = min( ans , abs(a[id1] - val));
                if( id1 > 0 ) ans = min( ans , abs(a[id1-1] - val));

            }

            cout<<ans<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
}