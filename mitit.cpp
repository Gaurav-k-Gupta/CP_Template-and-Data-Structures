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

    string s;
    cin>>s;

    int n = s.size();
    int cnt = 0;
    int tis = 0;
    for(int i = 0 ; i < n-5 ; ){
        string t = s.substr(i , 5);
        string t2 = s.substr(i , 2);
        if( t == "TIMIT" || t == "MITIT" || t == "TITIM" ){
            cnt++;
            cout<<i<<" "<<tis<<endl;
            if( tis ){
                tis--;
                s[i+4] = 'T';
                i += 4;
            }
            else{
                i += 5;
            }

            
            continue;
        }

        if( t2 == "TI" ){
            tis++;
            i += 2;
            continue;
        }

        tis = 0;
        i++;
        continue;
    }


    cout<<cnt<<endl;
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