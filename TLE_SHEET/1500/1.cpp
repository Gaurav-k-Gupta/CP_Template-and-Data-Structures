#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;



template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<ll,ll>> endStart(n);
        ordered_set<ll> start;
        for(int i=0 ; i<n ; i++){
            ll a , b;
            cin>>a;
            cin>>b;

            endStart[i] = { b , a };
            start.insert(a);

        }


        sort(endStart.begin() , endStart.end());
        

        ll cnt = 0;


        for(int i = n-1 ; i>=0 ; i--){
            ll ei = endStart[i].first;
            ll si = endStart[i].second;

            
            cnt += ( start.size() - start.order_of_key(si) - 1);

            auto it = start.find_by_order( start.order_of_key(si));

            if( it != start.end() ) start.erase(it);

        }

        cout<<cnt<<endl;

    }
}