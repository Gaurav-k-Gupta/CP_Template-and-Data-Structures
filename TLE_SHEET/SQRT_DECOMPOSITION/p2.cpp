/*
Author :- Gaurav Kumar
Date - 30/03/2025
*/

#include <iostream>
#include <vector>
#include<map>
#include<unordered_map>
#include<algorithm>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;



// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define ll int
#define vll vector<ll>

const ll block_size = 400;

struct Query{
    ll l , r , idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) < 
                make_pair(other.l / block_size, other.r);
    }
};

ll MAX_N = 100005;
vll a;
ll mp[100005]; // stores count of values in the cur range
ll cur_l = 0 , cur_r = -1;
ll cnt = 0;

void add( ll x ){
    if( x >= MAX_N ) return;
    mp[x]++;
    if( mp[x] == x ) cnt++;
    else if( mp[x] == x+1 ) cnt--;
}

void remove( ll x ){
    if( x >= MAX_N ) return;
    mp[x]--;
    if( mp[x] == x ) cnt++;
    else if( mp[x] == x-1 ) cnt--;
}


vll mo_s_algorithm( vector<Query> & queries ){
    sort(queries.begin() , queries.end());
    vll ans(queries.size());

    for(auto & q : queries){
        while (cur_l > q.l) {
            cur_l--;
            add(a[cur_l]);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(a[cur_r]);
        }
        while (cur_l < q.l) {
            remove(a[cur_l]);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(a[cur_r]);
            cur_r--;
        }
        // cout<<q.idx<<" "<<cnt<<endl;
        ans[q.idx] = cnt;
    }
    return ans;
}




void solve(){
    ll n , q;
    cin>>n>>q;

    a.resize(n);
    for(ll i = 0 ; i < n ; i++) cin>>a[i];


    vector<Query> queries(q);
    for(ll i = 0 ; i < q ; i++){
        ll l , r;
        cin>>l>>r;
        l--;
        r--;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].idx = i;
    }


    vll ans = mo_s_algorithm(queries);

    for(auto & x : ans) cout<<x<<'\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

}