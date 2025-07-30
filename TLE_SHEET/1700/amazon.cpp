#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// A = number of markets (1‑indexed)
// B[i] = price to buy at market i (0‑indexed in vector)
// C[k] = {u, v, w} roads (1‑indexed markets, w = empty‑cart cost)
// D = tax factor
//
// Returns a vector res of length A, where
// res[i] = min_j ( B[j] + D * dist(j → i

// bool check( vector<int> & parcels , long long total ){
//     long long cnt = 0;
//     for(auto & x : parcels){
//         cnt += 
//     }
// }

long minimizeMaxParcelLoad(vector<int> initialParcels , long additionalParcels){
    int n = initialParcels.size();
    long long mini = *min_element(initialParcels.begin() , initialParcels.end());
    long long maxi = *max_element(initialParcels.begin() , initialParcels.end());

    long long sum = 0;
    for(auto & x : initialParcels) sum += x;
    sum += additionalParcels;

    long long low = maxi , high = maxi + additionalParcels;
    while( low <= high ){
        long long mid = ( low + high ) / 2; 
        if( mid * n >= sum ) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int countPromotionalPeriods( vector<int> orders ){
    int n = orders.size();
    
    int cnt = 0;
    stack<pair<int,int>> stk;
    stk.push({ orders[n-1] , n-1 });

    for( int i = n-2 ; i >= 0 ; i-- ){
        while( !stk.empty() && stk.top().first < orders[i] ) stk.pop();

        if( !stk.empty() && stk.top().second > i+1 ) cnt++;
        stk.push({orders[i] , i});
    }

    while(!stk.empty()) stk.pop();


    stk.push({ orders[0] , 0 });

    for( int i = 1 ; i < n ; i++ ){
        while( !stk.empty() && stk.top().first < orders[i] ) stk.pop();

        if( !stk.empty() && stk.top().second < i-1 ) cnt++;
        stk.push({orders[i] , i});
    }

    return cnt;
}

// Example of how you might hook it up to I/O
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n;
    cin>>n;

    ll L = (n/2) + 1;
    ll R = n;
    ll times = 1;

    const ll MOD = 1e9 + 7;
    const ll INV2 = ( MOD + 1 ) / 2;

    ll sum = 0;
    while( L ){
        // sum of all numbers between L and R ( including both )
        ll a = R % MOD;
        ll b = (R + 1) % MOD;
        ll till_R = ( (a * b) % MOD * INV2 ) % MOD;

        a = (L - 1 + MOD) % MOD;
        b = L % MOD;
        ll till_L = ( (a * b) % MOD * INV2 ) % MOD;

        ll res = ( till_R - till_L + MOD ) % MOD;
        
        sum = ( sum + (res * times) % MOD ) % MOD;

        R = L - 1;
        if( R <= 0 ) break;
        times = n / R;
        L = ( n / (times + 1) ) + 1;
    }

    cout<<sum<<endl;
}
