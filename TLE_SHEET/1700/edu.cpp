#include <bits/stdc++.h>
using namespace std;

// big‑integer add of two non‐empty digit‑strings (no leading zeros unless "0")
static string bigAdd(const string &a, const string &b) {
    int i = a.size()-1, j = b.size()-1, carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int x = carry;
        if (i >= 0) x += a[i--]-'0';
        if (j >= 0) x += b[j--]-'0';
        carry = x/10;
        res.push_back(char('0' + (x%10)));
    }
    reverse(res.begin(), res.end());
    return res;
}

int solution(const vector<string> &crypt) {
    // collect distinct letters
    bool in_crypt[26] = {};
    vector<char> letters;
    bool leading[26] = {};
    for (auto &w : crypt) {
        if (w.size() > 1)
            leading[w[0]-'A'] = true;    
        for (char c : w)
            if (!in_crypt[c-'A']) {
                in_crypt[c-'A'] = true;
                letters.push_back(c);
            }
    }
    int L = letters.size();
    if (L > 10) return 0;               // can't map >10 distinct letters to 10 digits

    int assign_map[26];
    fill(assign_map, assign_map+26, -1);
    bool used_digit[10] = {};

    int count_solutions = 0;
    auto dfs = [&](auto&& self, int idx) -> void {
        if (idx == L) {
            // build digit-strings
            string s0, s1, s2;
            for (char c : crypt[0]) s0.push_back('0' + assign_map[c-'A']);
            for (char c : crypt[1]) s1.push_back('0' + assign_map[c-'A']);
            for (char c : crypt[2]) s2.push_back('0' + assign_map[c-'A']);
            // check sum
            if (bigAdd(s0, s1) == s2)
                ++count_solutions;
            return;
        }
        int ci = letters[idx] - 'A';
        for (int d = 0; d < 10; ++d) {
            if (used_digit[d]) continue;
            if (d == 0 && leading[ci]) continue;
            used_digit[d] = true;
            assign_map[ci] = d;
            self(self, idx+1);
            used_digit[d] = false;
            assign_map[ci] = -1;
        }
    };

    dfs(dfs, 0);
    return count_solutions;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> crypt(3);
    // read three words, one per line or space‑separated
    for(int i = 0; i < 3; i++){
        if(!(cin >> crypt[i])) return 0;
    }
    cout << solution(crypt) << "\n";
    return 0;
}
