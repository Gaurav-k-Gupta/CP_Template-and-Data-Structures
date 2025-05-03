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


vector<bool> is_prime( ll N ){      // N * log( log N )
    vector<bool> isPrime( N+1 , true );
    isPrime[0] = isPrime[1] = false;

    for(int i=4 ; i <= N ; i += 2 ) isPrime[i] = false;

    for(int i=3 ; i*i <= N ; i += 2){
        if( isPrime[i] ){
            int j = i*i;
            while( j <= N ){
                isPrime[j] = false;
                j += i + i;
            }
        }
    }
    return isPrime;
}

vector<ll> primes( ll N ){      // N * log logN
    vector<bool> isPrime = is_prime(N);
    vector<ll> Primes;
    for(ll i = 2 ; i <= N ; i++){
        if( isPrime[i] ) Primes.push_back(i); 
    }
    return Primes;
}


ll gcd( ll a , ll b ){
    return b ? gcd(b , a % b ) : a;
}


vector<ll> PRIMES = primes(1e5);
ll N = PRIMES.size();

vector<int> vis(1e5+5,0);
set<ll> st;
ll vid = 1;


void pre(){
    ++vid;
    st.clear();
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cout<<N<<endl;

    int t;
    cin>>t;

    while(t--){
        pre();
        int n;
        cin>>n;



        bool ans = true;
        

        for(int i = 0 ; i < n ; i++){
            ll ai;
            cin>>ai;

            // cout<<ai<<endl;

            if( !ans ) continue;

            int idx = 0;
            while( ai > 1 && idx < N && ( PRIMES[idx] * PRIMES[idx] <= ai ) ){

                if( ai % PRIMES[idx] != 0 ){ idx++; continue; }


                if( vis[PRIMES[idx]] == vid ){
                    // cout<<PRIMES[idx]<<" "<<ai<<endl;
                    ans = false;
                    break;
                }
                
                vis[PRIMES[idx]] = vid;

                while( ai % PRIMES[idx] == 0 ){
                    ai /= PRIMES[idx];
                }
                idx++;
            }
            if( !ans ) continue;
            if( ai > 1 ){
                if( ai < 1e5 ){
                    if( vis[ai] == vid ) {ans = false; continue;}
                }
                else if( st.find(ai) != st.end() ) ans = false;

                st.emplace(ai);
            }
        }

        if(ans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }


}