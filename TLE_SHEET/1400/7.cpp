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


int color(string& s , vector<int>& col){
    int n = s.size();
    stack<int> stk;

    bool a = false , b = false;

    int cnt1 = 0 , cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        if( s[i] == '(' ) stk.push(i);
        else{
            if( stk.empty() ){
                col[i] = 2;
                cnt2++;
            }
            else{
                int idx = stk.top();

                col[i] = 1;
                col[idx] = 1;
                stk.pop();

                cnt1++;
            }
        }
    }

    if( cnt1 ) a = true;
    if( cnt2 ) b = true;

    while( !stk.empty() ){
        col[stk.top()] = 2;
        cnt2--;
        stk.pop();
    }

    if( !cnt2 ){
        if( a && b ) return 2;
        return 1;
    }
    else{
        return -1;
    }
}

void print( int ans , vi & col , int sidha){
    cout<<ans<<endl;
    int n = col.size();
    if(sidha){
        for(auto it : col){
            if( ans == 2 ) cout<<it<<" ";
            else cout<<"1 ";
        }
        cout<<endl;
    }
    else{
        for(int i = n-1 ; i >= 0 ; i--){
            if(ans == 2 ) cout<<col[i]<<" ";
            else cout<<"1 ";
        }
        cout<<endl;
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<int> col1(n , 0);
        vector<int> col2(n , 0);

        string s2 = s;

        reverse(s2.begin() , s2.end());

        int ans1 = color( s , col1 );
        int ans2 = color( s2 , col2 );

        if( ans1 == -1 && ans2 == -1 ){
            cout<<"-1"<<endl;
        }
        else if( ans2 == -1 ){
            print(ans1 , col1 , 1);
        }
        else if( ans1 == -1 ){
            print(ans2 , col2 , 0);
        }
        else if( ans1 < ans2 ){
            print(ans1 , col1 , 1);
        }
        else print(ans2 , col2 , 0);
    }

}