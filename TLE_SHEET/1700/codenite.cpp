#include <bits/stdc++.h>
using namespace std;

/**
 * Computes, for each center i in [0..n-1], the number of odd-length palindromes
 * centered at i in string s.
 * 
 * Returns a vector d1 of length n, where
 *   d1[i] = the count of palindromes of odd length centered at i.
 * Equivalently, d1[i] = the maximum radius k such that
 *   s[i - (k-1)]..s[i + (k-1)] is a palindrome,
 * and hence there are k distinct odd palindromes (lengths 1, 3, 5, ..., 2k-1).
 */
vector<int> manacher_odd(const string &s) {
    int n = s.size();
    vector<int> d1(n);
    int l = 0, r = -1;
    // d1[i] will be at least 1 (the single-character palindrome)
    for (int i = 0; i < n; i++) {
        int k = (i > r ? 1 : min(d1[l + (r - i)], r - i + 1));
        // try to expand around center i
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k;
        // update the current rightmost palindrome [l..r]
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    return d1;
}

vector<long long> oddPalindromes(const string &A, const vector<int> &B) {
    int N = A.size();
    // precompute with Manacher
    vector<int> d1 = manacher_odd(A);
    vector<long long> C;
    C.reserve(B.size());
    for (int bi : B) {
        int idx = bi - 1;           // convert to 0-based
        C.push_back(d1[idx]);       // d1[idx] is already the count
    }
    return C;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example of reading input; adjust as needed for your environment
    // First line: string A
    // Second line: integer Q
    // Next line: Q space-separated integers B[i]
    string A;
    cin >> A;
    int Q;
    cin >> Q;
    vector<int> B(Q);
    for(int i = 0; i < Q; i++){
        cin >> B[i];
    }

    vector<long long> C = oddPalindromes(A, B);
    for (auto x : C) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
