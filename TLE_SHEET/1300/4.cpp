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

    vector<ll> prm = primes(1e3+1);
    
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vll a(n);
        for(int i=0 ; i<n ; i++) cin>>a[i];

        ll si = prm.size();
        unordered_map<ll,ll> mp;
        for(int i=0 ; i<n ; i++){
            ll val = a[i];

            int idx = 0;
            while( val && idx < si ){
                ll div = prm[idx];
                if( val % div == 0 ){
                    mp[div]++;
                    val /= div;
                }
                else{
                    idx++;
                }
            }

            if( val ) mp[val]++;
        }

        bool ch = true;
        for(auto it : mp){
            if( it.second % n ){
                ch = false;
                break;
            }
        }

        if( ch ) yes;
        else no;
    }
}