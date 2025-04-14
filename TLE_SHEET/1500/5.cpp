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

        vector<ll> a(n) , b(n) , sum(n);

        for(int i = 0 ; i<n ; i++) cin>>a[i];
        for(int i = 0 ; i<n ; i++){
            cin>>b[i];
            sum[i] = b[i];
            if( i ) sum[i] += sum[i-1];
            // cout<<sum[i]<<" ";
        }
        // cout<<endl;

        vector<ll> ans( n+1 , 0 );
        vector<ll> res( n+1 , 0 );

        for(int i = 0 ; i < n ; i++){
            ll red = 0;
            if( i ) red = sum[i-1];
            // cout<<red<<endl;
            int low = i , high = n-1;

            // cout<<i<<" :- "<<endl;


            ll chk = a[i];

            while( low <= high ){
                int mid = ( low + high ) /2 ;
                ll val = sum[mid] - red;
                // cout<<low<<" "<<high<<" "<<val<<endl;
                if( val <= chk ) low = mid + 1;
                else high = mid - 1;

            }
            // cout<<high<<endl;
            ll leftOut = chk + red;
            if( high >= 0 ) leftOut -= sum[high];
            ans[high+1] += leftOut;

            // cout<<leftOut<<" "<<high+1<<endl;
            
            if( high >= i ){
                res[i]++;
                res[high+1]--;
            }

        }

        ll overlap = 0;
        for( int i = 0 ; i <= n ; i++){
            overlap += res[i];
            res[i] = overlap;
        }

        for(int i = 0 ; i<n ; i++){
            ans[i] += b[i] * res[i];
            cout<<ans[i]<<" ";
        }

        cout<<endl;

    }
}