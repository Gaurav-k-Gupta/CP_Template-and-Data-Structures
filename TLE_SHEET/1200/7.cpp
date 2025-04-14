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
        int n , m;
        cin>>n>>m;

        vector<vector<int>> a( m , vector<int>( n ));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin>>a[j][i];
            }
        }

        // for(auto it : a ){
        //     for(auto itr : it) cout<<itr<<" ";
        //     cout<<endl;
        // }

        ll total = 0;
        for(int i = 0 ; i < m ; i++){
            sort(a[i].begin() , a[i].end());

            int j = n-2;
            ll diff = 0;
            while( j >= 0 ){
                diff += a[i][n-1] - a[i][j]; 
                j--;
            }

            // cout<<diff<<endl;

            j = n-1;
            ll cnt = 0;
            ll sub = n-1;

            while( j > 0 ){
                cnt += diff;
                diff -= ( a[i][j] - a[i][j-1] )*sub ;
                sub--;
                j--;
            }

            total += cnt;
        }

        cout<<total<<endl;

    }
}