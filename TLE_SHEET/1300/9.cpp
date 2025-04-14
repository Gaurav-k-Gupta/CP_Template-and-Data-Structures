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
        int n;
        cin>>n;

        unordered_map<int,int> mp;
        vector<vector<int>> a(n);

        for(int i = 0 ; i < n ; i++){
            int ki;
            cin>>ki;

            a[i].resize(ki);
            for(int j = 0 ; j < ki ; j++){ cin>>a[i][j]; mp[a[i][j]]++; }
        }

        bool ans = false;
        for(int i = 0 ; i < n ; i++){
            bool res = true;
            for(auto it : a[i]){
                if( mp[it] <= 1 ){
                    res = false;
                    break;
                }
            }

            if( res ){
                ans = true;
                break;
            }
        }

        if( ans ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}