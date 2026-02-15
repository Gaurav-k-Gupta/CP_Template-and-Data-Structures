#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll complement(ll n){
    ll mask = ( 1LL << 33 ) - 1;
    return n ^ mask;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vector<ll> a(n);
        multiset<ll> st;
        unordered_map<ll,vector<ll>> mp;
        for(ll i = 0; i < n ; i++){
            cin>>a[i];
            st.insert( a[i] );
            mp[a[i]].push_back( i+1 );
        }

        ll curVal = *max_element(a.begin() , a.end());
        st.erase( curVal );

        vector<ll> res = { curVal };
        

        ll i = 1;

        while( i < n ){

            if( i <= 32 ){
                ll comp = complement( curVal );
                ll maxi = 0;
                ll er = 0;
                // multiset<ll> st2;
                for(auto it : st){
                    // cout<<it<<" ";
                    ll v = it & comp;
                    if( v > maxi ){
                        er = it;
                        maxi = v;
                    }
                    else if( v == maxi ){
                        er = max(er , it);
                    }
                }
                // cout<<endl;
                

                curVal |= er;

                // cout<<er<<" "<<curVal<<endl;

                st.erase( er );
                res.push_back( er );
            }
            else{
                res.push_back( *st.begin() );
                st.erase( st.begin() );
            }
            i++;
        }


        ll ans = 0;
        ll cur = 0;

        vector<ll> idx( n );
        for(ll i = 0 ; i < n ; i++){
            // cout<<res[i]<<endl;
            idx[n-i-1] = mp[res[i]].back();
            mp[res[i]].pop_back();
            cur |= res[i];
            ans += cur;
        }

        cout<<ans<<endl;
        for(auto it : idx) cout<<it<<" ";
        cout<<endl;
    }
}