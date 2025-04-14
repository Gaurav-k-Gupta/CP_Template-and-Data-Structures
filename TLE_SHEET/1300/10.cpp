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

        vector<pair<int,int>> a;
        vector<int> b;
        for(int i = 1 ; i <= n ; i++){
            int val;
            cin>>val;

            if( val < i ){
                a.push_back({val , i});
                b.push_back(val);
            }
        }


        sort(a.begin() , a.end());
        sort(b.begin() , b.end());


        ll cnt = 0;
        for(auto it : a){
            ll idx = it.second;
            cnt += b.end() - lower_bound(b.begin() , b.end() , idx+1) ;
        }

        cout<<cnt<<endl;
    }
    return 0;
}