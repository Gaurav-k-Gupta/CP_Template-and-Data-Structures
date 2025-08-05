/*
Author :- Gaurav Kumar
Date - 30/03/2025
*/

#include <iostream>
#include <unordered_set>
#include <vector>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;



// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define ll int
#define vll vector<ll>

ll n , m , q;
vll on;
vector<unordered_set<ll>> adj;
ll B = 450;
vll sol;
unordered_set<ll> heavy;


void online( ll u ){
    on[u] = 1;
    for(auto & i : heavy){
        if( adj[i].find(u) != adj[i].end() ){
            sol[i]++;
        }
    }
}

void offline( ll u ){
    on[u] = 0;
    for(auto & i : heavy){
        if( adj[i].find(u) != adj[i].end() ){
            sol[i]--;
        }           
    }
}

void add_friend( ll u , ll v ){
    adj[u].insert(v);
    adj[v].insert(u);

    if( adj[u].size() > B ){
        if(on[v]) sol[u]++;
    }
    else if( adj[u].size() == B ){
        heavy.insert(u);
        ll cnt = 0;
        for(auto & i : adj[u]){
            if( on[i] ) cnt++;
        }
        sol[u] = cnt;
    }

    if( adj[v].size() > B ){
        if( on[u] ) sol[v]++;
    }
    else if( adj[v].size() == B ){
        heavy.insert(v);
        ll cnt = 0;
        for(auto & i : adj[v]){
            if( on[i] ) cnt++;
        }
        sol[v] = cnt;
    }
}

void del_friend( ll u , ll v ){
    adj[u].erase(v);
    adj[v].erase(u);

    if( adj[u].size() >= B ){
        if(on[v]) sol[u]--;
    }
    else if( adj[u].size() == B-1 ){
        heavy.erase(u);
    }

    if( adj[v].size() >= B ){
        if( on[u] ) sol[v]--;
    }
    else if( adj[v].size() == B-1 ){
        heavy.erase(v);
    }
}

ll cnt_online_friends( ll u ){
    if( heavy.find(u) != heavy.end() ){
        return sol[u];
    }

    ll cnt = 0;
    for(auto & i : adj[u]){
        if(on[i]) cnt++;
    }

    return cnt;
}


void solve(){
    cin>>n>>m>>q;
    on.resize(n , 0);
    ll o;
    cin>>o;
    for(int i = 0 ; i < o ; i++){
        ll x;
        cin>>x;
        on[x-1] = 1;
    }

    adj.resize(n);
    for(int i = 0 ; i < m ; i++){
        ll u , v;
        cin>>u>>v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }

    sol.resize(n , 0);
    

    for(int i = 0 ; i < n ; i++){
        ll si = adj[i].size();
        if( si >= B ){
            // Heavy node
            heavy.insert(i);
            ll cnt = 0;
            for(auto & v : adj[i]){
                if( on[v] ) cnt++;
            }

            sol[i] = cnt;
        }
    }

    while(q--){
        char ch;
        cin>>ch;

        if( ch == 'O' ){
            ll u;
            cin>>u;
            online(u-1);
        }
        else if( ch == 'F' ){
            ll u;
            cin>>u;
            offline(u-1);
        }
        else if( ch == 'A' ){
            ll u , v;
            cin>>u>>v;
            add_friend(u-1 , v-1);
        }
        else if( ch == 'D' ){
            ll u , v;
            cin>>u>>v;
            del_friend(u-1 , v-1);
        }
        else{
            ll u;
            cin>>u;
            cout<<cnt_online_friends(u-1)<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    

        solve();

}