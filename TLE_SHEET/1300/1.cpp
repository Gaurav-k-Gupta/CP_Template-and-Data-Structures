#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        map<pair<int,int>,int> mp;
        ll cnt = 0;
        for(int i=0 ; i<n ; i++){
            int e;
            cin>>e;

            int modx = e % x;
            int mody = e % y;

            cnt += mp[make_pair(-modx,mody)];
            cnt += mp[make_pair(x-modx,mody)];

            mp[make_pair(modx , mody)]++;
        }

        cout<<cnt<<endl;

    }
}