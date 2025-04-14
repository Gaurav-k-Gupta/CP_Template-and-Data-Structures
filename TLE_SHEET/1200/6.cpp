#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n ;
        cin>>n;

        vector<ll> a(n);
        ll con = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
            if( i ) con += abs(a[i-1] - a[i]);
        }

        if( con == 0 ){
            cout<<"1"<<endl;
            continue;
        }

        int inc = -1;
        int cnt = 0;
        for(int i = 1 ; i < n ; i++){
            if( inc == -1 ){
                if( a[i] > a[i-1] ) inc = 1;
                else if( a[i] < a[i-1] ) inc = 0;
                continue;
            }
            if( inc && a[i] < a[i-1] ){
                cnt++;
                inc = 0;
                continue;
            }
            if( !inc && a[i] > a[i-1] ){
                cnt++;
                inc = 1;
                continue;
            }
        }

        cout<<cnt+2<<endl;

    }
}