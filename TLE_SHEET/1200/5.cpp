#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        ll n, k;
        cin>>n>>k;

        vector<vector<int>> adj(k+1);

        for(int i = 0 ; i<n ; i++){
            int col;
            cin>>col;

            adj[col].push_back(i+1);
        }


        int ans = INT_MAX;
        for(auto col : adj){
            if( col.size() == 0 ) continue;

            vector<int> diff;
            int si = col.size();
            diff.push_back(col[0] - 1);
            for(int i = 1 ; i < si ; i++){
                diff.push_back(col[i] - col[i-1] - 1);
            }

            diff.push_back(n - col[si-1]);


            sort( diff.begin() , diff.end() );
            ans = min( ans , max(diff[si-1] , diff[si]/2));
        }

        cout<<ans<<endl;
    }
}