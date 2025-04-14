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
        for(int i = 0 ; i < n ; i++) cin>>a[i];


        deque<int> dq;

        for(int i = 0 ; i < n ; i++){
            int val = a[i];
            int x = dq.size(); 
            double o1 = (double)val / (double)(x+1);
            double o2 = dq.empty() ? 0.00 : (double)val / (double)dq.front();
            double o3 = 1.00;

            if( o1 >= max(o2 , o3)){
                dq.push_back(val);
            }
            else if( o2 >= max( o1 , o3 )){
                dq.push_back(val);
                dq.pop_front();
            }
            
            cout<<dq.size()<<" ";
        }

        cout<<endl;
    }
    return 0;
}