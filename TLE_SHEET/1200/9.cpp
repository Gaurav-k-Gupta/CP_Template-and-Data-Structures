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

        int cnt = 0;
        int currSize = 0;
        sort(a.begin() , a.end());

        int i = 1;
        while( i < n ){
            int tmp = 1;
            while( i < n && a[i] == a[i-1] ){
                i++;
                tmp++;
            }

            cnt += max( 0 , tmp - currSize);
            currSize = tmp;

            if( i < n && a[i] - a[i-1] != 1 ) currSize = 0;
            i++;
        }
        
        if( i == n ) cnt += max( 0 , 1 - currSize);
        // currSize = tmp;
        cout<<cnt<<endl;
    }
}