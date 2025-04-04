#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<ll> a(n);
        ll ev = 0 , od = 0;
        ll mod4 = 0;
        bool is_4 = false;
        for(int i=0 ; i<n ; i++){
            cin>>a[i];

            if( a[i] % 2 ) od++;
            else ev++;

            if( i == 0 ) mod4 = a[i] % 4;
            else{
                if( a[i] % 4 != mod4 ) is_4 = true;
            }
        }

        if( ev && od ) cout<<2<<endl;
        else{
            ll v = 4;
            ll modv = 0;
            bool is_v = false;
            while( !is_v ){
                for(int i=0 ; i<n ; i++){
    
                    if( i == 0 ) modv = a[i] % v;
                    else{
                        if( a[i] % v != modv ) is_v = true;
                    }
                }

                if( is_v ) break;
                v *= 2;
            }
            cout<<v<<endl;
        }
    }
}