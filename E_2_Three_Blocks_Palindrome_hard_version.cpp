#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;



// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// void using_pbds(){
//     ordered_set<int> X;
//     X.insert(1);
//     X.insert(2);
//     X.insert(4);
//     X.insert(8);
//     X.insert(16);

//     cout<<*X.find_by_order(1)<<endl; // 2
//     cout<<*X.find_by_order(2)<<endl; // 4
//     cout<<*X.find_by_order(4)<<endl; // 16
//     cout<<(X.end()==X.find_by_order(6))<<endl; // true

//     cout<<X.order_of_key(-5)<<endl;  // 0
//     cout<<X.order_of_key(1)<<endl;   // 0
//     cout<<X.order_of_key(3)<<endl;   // 2
//     cout<<X.order_of_key(4)<<endl;   // 2
//     cout<<X.order_of_key(400)<<endl; // 5
// }


#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pair<int,int>>
#define ppll pair<pair<ll,ll>>
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define loop(i,n,d) for(int i=0 ; i<n ; i += d)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(a) (a).begin() , (a).end()
#define prt(a) cout<<a<<endl

// const ll mod = 998244353;
// const ll INF = 1e12;



int pre[201][200001];
// int suf[201][200001];



void solve(){

    // memset(pre , 0 , sizeof(pre));
    // memset(suf , 0 , sizeof(suf));

    int n;
    cin>>n;

    vector<int> a(n);
    for(ll i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    // vector<vector<ll>> pre( 201 , vector<ll>( n , 0 ));
    // vector<vector<ll>> suf = pre;

    int maxi = 0;

    // for(ll i = 0 ; i < n ; i++){
    //     pre[a[i]][i] = 1;
    // }

    // for(ll i = n-1 ; i >= 0 ; i--){
    //     suf[a[i]][i] = 1;
    // }

    for(int i = 0 ; i < n ; i++){
        for(int v = 1 ; v <= 200 ; v++){
            pre[v][i] = 0;
            pre[v][i] += ( i ? pre[v][i-1] : 0 );
        }

        pre[a[i]][i] = 1 + ( i ? pre[a[i]][i-1] : 0 );
    }

    for(int v = 1 ; v <= 200 ; v++) maxi = max( maxi , pre[v][n-1] ); 

    vector<vector<int>> adj( 201 );
    for(ll i = 0 ; i < n ; i++){
        adj[a[i]].push_back(i);
    }


    for(int f = 1 ; f <= 200 ; f++){
        if( adj[f].empty() ) continue;
        int i = 0 , j = adj[f].size() - 1;
        // cout<<i<<" "<<j<<endl;
        while( i < j ){
            int cnt = 2*(i+1);

            int i1 = adj[f][i] , i2 = adj[f][j];

            int mx = 0;
            for(int m = 1 ; m <= 200 ; m++){
                int fq = pre[m][i2-1] - pre[m][i1];
                mx = max( mx , fq );
            }

            cnt += mx;

            maxi = max( maxi , cnt );
            i++;
            j--;

            // cout<<f<<endl;
            // cout<<i<<" "<<j<<endl;

            // cout<<maxi<<endl;
        }

        // cout<<f<<endl;
    }

    cout<<maxi<<endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    


    int t;
    cin>>t;

    while(t--){
        solve();
    }

}