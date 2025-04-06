#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> digAns(10 , 0);


ll gcd( ll a , ll b ){
    return b ? gcd(b , a%b) : a;
}

ll lcm( ll a , ll b ){
    return (a*b)/gcd(a , b);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll n , x , y;
        cin>>n>>x>>y;

        ll cntX = n / x;
        ll cntY = n / y;

        ll cntXY = n / lcm(x,y);

        cntX -= cntXY;
        cntY -= cntXY;

        ll ans = ( (n * (n+1))/2 - ((n - cntX)*(n - cntX + 1))/2 ) - ( cntY * (cntY + 1 ) / 2);

        cout<<ans<<endl;

    }
}