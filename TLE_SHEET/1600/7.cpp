#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calAns(const vector<ll>& freq, ll k, ll n){
    // number of changes = n - sum of the top k frequencies (capped at n/k each)
    vector<ll> f = freq;
    sort(f.rbegin(), f.rend());
    ll keep = 0;
    ll each = n / k;
    for(int i = 0; i < k; i++){
        keep += min(f[i], each);
    }
    return n - keep;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> freq(26, 0);
    for(char c : s) freq[c - 'a']++;

    // find best k
    ll bestChanges = n, bestK = 1;
    for(ll k = 1; k <= 26; k++){
        if(n % k != 0) continue;
        ll changes = calAns(freq, k, n);
        if(changes < bestChanges){
            bestChanges = changes;
            bestK = k;
        }
    }

    // which letters do we keep?
    ll each = n / bestK;
    vector<pair<ll,int>> letters; // (freq, letter)
    for(int c = 0; c < 26; c++){
        letters.emplace_back(freq[c], c);
    }
    sort(letters.rbegin(), letters.rend()); 
    vector<bool> inSet(26,false);
    for(int i = 0; i < bestK; i++){
        inSet[ letters[i].second ] = true;
    }

    // how many more of each letter we still need
    vector<ll> need(26, 0);
    for(int c = 0; c < 26; c++){
        if(inSet[c]) need[c] = each;
    }

    string t = s;
    vector<int> toChange; 
    // pass 1: keep what we can
    for(int i = 0; i < n; i++){
        int c = s[i] - 'a';
        if(inSet[c] && need[c] > 0){
            // keep
            t[i] = s[i];
            need[c]--;
        } else {
            // must change
            toChange.push_back(i);
        }
    }

    // pass 2: fill the rest
    int idx = 0;
    for(int c = 0; c < 26; c++){
        while(need[c] > 0){
            int pos = toChange[idx++];
            t[pos] = char('a' + c);
            need[c]--;
        }
    }

    // output
    cout << bestChanges << "\n" << t << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
