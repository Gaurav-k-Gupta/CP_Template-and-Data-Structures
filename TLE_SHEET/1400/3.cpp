#include<bits/stdc++.h>
using namespace std;

#define ll long long


bool common(ll & l , ll & r , ll al , ll ar){
    if( r < al || l > ar ) return false;
    l = max( l , al );
    r = min( r , ar );
    return true;
}


bool check( vector<pair<ll,ll>> &a , ll k ){
    ll l = 0 , r = 0;

    for( auto it : a ){
        r += k;
        l -= k;
        if( !common( l , r , it.first , it.second ) ) return false;
        // cout<<l<<" "<<r<<endl;
    }
    return true;
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<pair<ll,ll>> a(n);
        ll h = 0;
        for(int i=0 ; i<n ; i++){
            cin>>a[i].first>>a[i].second;
            h = max( h , a[i].second );
        }

        ll l = 0;
        h *= 2LL;
        
        while( l <= h ){
            ll mid = ( l + h )/2;
            // cout<<l<<" "<<h<<" "<<mid<<endl;
            if( check( a , mid ) ) h = mid - 1;
            else l = mid + 1;
        }

        cout<<l<<endl;

    }
}