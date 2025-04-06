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

    for(int i=0 ; i <= 9 ; i++){
        for(int j=0 ; j <= 9 ; j++){
            for(int k=0 ; k <= 9 ; k++){
                int sum = i + j + k;
                if( sum <= 9 ) digAns[sum]++;
            }
        }
    }


    while(t--){
        ll n;
        cin>>n;

        ll tripletsCnt = 1;

        while( n ){
            tripletsCnt *= digAns[ n % 10 ];
            n /= 10;
        }

        cout<<tripletsCnt<<endl;

    }
}