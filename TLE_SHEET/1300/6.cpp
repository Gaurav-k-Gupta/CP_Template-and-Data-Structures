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

        vector<int> a(n) , b(n);
        for(int i = 0 ; i < n ; i++) cin>>a[i];

        for(int i=0 ; i < n ; i++){
            cin>>b[i];

            b[i] = a[i] - b[i];
        }

        vector<int> ans;
        int maxi = *max_element(b.begin() , b.end());

        for(int i = 0 ; i < n ; i++){
            if( b[i] == maxi) ans.push_back(i+1);
        }

        cout<<ans.size()<<endl;
        for(auto it : ans) cout<<it<<" ";
        cout<<endl;
        
    }
}