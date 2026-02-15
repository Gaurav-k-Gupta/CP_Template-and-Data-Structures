#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
// template <typename T>ostream& operator<<(ostream& os,const vector<T>& vec){for(const auto&elem:vec){os<<elem<<" ";}return os;}
// template <typename T>ostream& operator<<(ostream& os, const vector<vector<T> >& vec) {for(const auto& row:vec){os<<" "<<row<< endl;}return os;}
#define endl "\n"
#define mkp make_pair
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define mod 1000000007
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl

/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
/* وَهُوَ مَعَكُمْ أَيْنَ مَا كُنتُمْ */
/* فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا */
/* لا فَتى اِلاّ عَلِىّ، لا سَیفَ اِلاّ ذُوالفَقار */
/* Always push harder than yesterday */
/* Hard work beats talent when talent doesn't work hard */
/* Implementation is always better than preparation */

// #ifndef ONLINE_JUDGE
//     #include "Debug.cpp"
//     #define check cerr << "Reached Line " << __LINE__ << endl
// #else
//     #define debug(...)
//     #define debugArr(...)
//     #define check
// #endif
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<vector<int>>v(2,vector<int>(n));
    for(int i=0;i<n;i++) cin>>v[0][i];
    for(int i=0;i<n;i++) cin>>v[1][i];
    vector<vector<pair<int,int>>>m(2,vector<pair<int,int>>(n));
    m[1][n-1] = {v[1][n-1],v[1][n-1]};
    for(int i=n-2;i>=0;i--){
        m[1][i].first = min(v[1][i],m[1][i+1].first);
        m[1][i].second = max(v[1][i],m[1][i+1].second);
    }
    m[0][0] = {v[0][0],v[0][0]};
    for(int i=1;i<n;i++){
        m[0][i].first = min(v[0][i],m[0][i-1].first);
        m[0][i].second = max(v[0][i],m[0][i-1].second);
    }
    // debug(m);
    int ans = 0ll;
    vector<pair<int,int>> mM(n);
    for(int i=0;i<n;i++){
        pair<int,int>p;
        int mini = min(m[0][i].first,m[1][i].first);
        int maxi = max(m[0][i].second,m[1][i].second);
        p.first = mini;
        p.second = maxi;
        mM[i] = p;
        // debug(p);
        // if(p.first<=p.second)ans = max(ans,(1ll*p.first*((2ll*n)-p.second+1)));
    }

    sort(mM.begin() , mM.end());
        int lmax = 2*n;
        for(int i = n-1 ; i >= 0 ; i--){
            lmax = min( lmax , mM[i].second );
            int mi = mM[i].first;
            if( i ) mi -= mM[i-1].first;

            ans += mi * (2*n - lmax + 1);
        }
    cout<<ans<<endl;
}

int32_t main(){
    int test=1;
    cin>>test;
    for(int t=1;t<=test;t++){
        // cerr<<"\nTest: " <<t<< "---------\n\n";
        solve();
    }
    return 0;
}