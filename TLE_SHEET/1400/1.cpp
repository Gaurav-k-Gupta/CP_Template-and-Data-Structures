#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        // int  = 0;
        int totalDigits = 0;

        vector<int> zeros;

        for(int i=0 ; i<n ; i++){
            int val;
            cin>>val;

            // find the number of the digits of the val
            double si = log10(val);
            int cl = ceil(si);
            int flr = floor(si);
            if( cl == flr ) totalDigits += flr + 1;
            else totalDigits += cl;

            // calculate count of ending zeros
            int cnt = 0;
            while( (val % 10) == 0 ){
                val /= 10;
                cnt++;
            }

            zeros.push_back(cnt);

        }

        sort(zeros.begin() , zeros.end());

        for(int i = zeros.size() - 1 ; i >= 0 ; i -= 2){
            totalDigits -= zeros[i];
        }


        if( totalDigits > m ) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;



    }
}