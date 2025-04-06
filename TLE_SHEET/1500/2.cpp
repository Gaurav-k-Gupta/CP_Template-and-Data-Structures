#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0 ; i<n ; i++) cin>>a[i];

        sort(a.begin() , a.end());

        int i = 0 , j = n-1;

        int x = 0;
        ll attackCnt = 0;
        while( i <= j ){
            if( i == j ){
                if( a[j] == 1 ) attackCnt++;
                else attackCnt += ceil( (double)(a[j] - x) / 2.00 ) + 1;
                break;
            }


            if( x == a[j] ){
                attackCnt++;
                j--;
                x = 0;
                continue;
            }

            if( a[i] + x > a[j] ){
                attackCnt += a[j] - x;
                a[i] -= a[j] - x;
                x = a[j];
            }
            else{
                x += a[i];
                attackCnt += a[i];
                i++;
            }


            // cout<<i<<" "<<j<<" "<<attackCnt<<endl;
        }

        cout<<attackCnt<<endl;
    }
}