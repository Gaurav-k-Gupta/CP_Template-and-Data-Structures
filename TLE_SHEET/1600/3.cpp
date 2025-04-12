#include<bits/stdc++.h>
using namespace std;

#define ll long long

void update( ll & i , stack<ll>& stk , string& s , vector<ll>& vis){
    // cout<<i<<endl;
    ll n = vis.size();
    if( i == n ){
        vis[stk.top()] = 1;
        stk.pop();
        return;
    }

    if( stk.empty() ){
        stk.push(i);
        i++;
    }

    char tp = s[stk.top()];
    
    while( i < n && s[i] >= tp ){
        stk.push(i);
        tp = s[i];
        i++;
    }

    vis[stk.top()] = 1;
    stk.pop();
    return;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        ll pos;
        cin>>pos;

        ll n = s.size();

        vector<ll> vis(n , 0);
        stack<ll> stk;
        ll i = 0;

        while( pos > n ){
            update( i , stk , s , vis );
            pos -= n;
            n--;
        }

        // for(auto it : vis) cout<<it<<" ";
        // cout<<endl;

        ll idx = 0;
        while(pos){
            if( vis[idx] ){
                idx++;
                continue;
            }
            pos--;
            if( !pos ) break;
            idx++;
        }

        cout<<s[idx];
    }
    // cout<<endl;
}