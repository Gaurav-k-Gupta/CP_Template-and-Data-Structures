#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>


// Euclidean method
int gcd(int a , int b){
    return b ? gcd( b , a % b ) : a ;
}



int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vi a(n);
        vi ks;
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
            if( i > 0 && (n % i) == 0 ){
                ks.push_back(i);
            }
        }

        // cout<<gcd( 27 , 12 )<<endl;

        int cnt = 1;
        for(auto it : ks){
            int k = it;
            // cout<<k<<endl;
            int GCD = 0;
            for(int i=0 ; i<n-k ; i++){
                GCD = gcd( GCD , abs(a[i] - a[i+k]));
            }
            // cout<<GCD<<endl;
            if( GCD != 1 ) cnt++;
        }

        cout<<cnt<<endl;

        // cout<<endl;

    }
}