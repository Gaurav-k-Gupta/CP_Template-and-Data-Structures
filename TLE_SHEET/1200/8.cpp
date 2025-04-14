#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }


        int l = 0 , r = n-1;
        int mn = 1 , mx = n;
        while( l < r ){
            if( a[l] == mn ){
                l++;
                mn++;
            }
            else if( a[l] == mx ){
                l++;
                mx--;
            }
            else if( a[r] == mn ){
                r--;
                mn++;
            }
            else if( a[r] ==mx ){
                r--;
                mx--;
            }
            else break;
        }

        if( l == r ) cout<<"-1"<<endl;
        else cout<<l+1<<" "<<r+1<<endl;
    }
}