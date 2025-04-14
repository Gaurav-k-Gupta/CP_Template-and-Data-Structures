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
        int n,q;
        cin>>n>>q;

        vector<ll> a(n) , maxi(n) , sum(n);


        for(int i = 0 ; i<n ; i++){
            cin>>a[i];
            
            if( !i ){
                maxi[i] = a[i];
                sum[i] = a[i];
            }
            else{
                maxi[i] = max(a[i] , maxi[i-1]);
                sum[i] = a[i] + sum[i-1];
            }
        }

        vector<ll> ans;
        while(q--){
            int k;
            cin>>k;

            int idx = upper_bound(maxi.begin() , maxi.end() , k) - maxi.begin() - 1;

            if( idx >= 0 ) ans.push_back(sum[idx]);
            else ans.push_back(0);
        }

        for(auto it : ans) cout<<it<<" ";
        cout<<endl;
    }
}