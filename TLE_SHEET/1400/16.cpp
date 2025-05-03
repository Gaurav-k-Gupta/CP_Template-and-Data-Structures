#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;

        string s;
        cin>>s;

        ll sheepCnt = 0;
        for(int i = 0 ; i < n ; i++){
            if( s[i] == '*' ) sheepCnt++;
        }

        ll i = 0;
        while( i < n && s[i] != '*' ) i++;

        ll prev = i;
        ++i;

        ll cSheepCnt = 1;

        ll cnt = 0;

        while( i < n ){
            while( i < n && s[i] != '*' ) i++;

            if( i == n ) break;

            ll uSheepCnt = sheepCnt - cSheepCnt;
            ll dist = i - prev - 1;

            cnt += min(cSheepCnt*dist , uSheepCnt*dist);

            cSheepCnt++;
            prev = i;
            ++i;
        }

        cout<<cnt<<endl;
    }
    return 0;
}