#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for (const auto &elem : vec)
    {
        os << elem << " ";
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec)
{
    for (const auto &row : vec)
    {
        os << " " << row << endl;
    }
    return os;
}
#define int long long
#define endl "\n"
#define mkp make_pair
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 1000000007
#define no cout << "NO" << endl
#define yes cout << "YES" << endl

/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
/* وَهُوَ مَعَكُمْ أَيْنَ مَا كُنتُمْ */
/* فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا */
/* لا فَتى اِلاّ عَلِىّ، لا سَیفَ اِلاّ ذُوالفَقار */
/* Always push harder than yesterday */
/* Never feel demotivated */
/* Hard work beats talent when talent doesn't work hard */
/* Implementation is always better than preparation */

class Solution
{
public:
    void solve()
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        unordered_set<char> unique;
        for (int i = 0; i < n; i++) unique.insert(a[i]);

        vector<char> v(all(unique));
        int sz = v.size();
        int ans = INT_MIN;
        k = min(k, sz);
        vector<bool> alpha(26, 0);
        for (int mask = 0; mask < (1 << sz); mask++)
        {
            for(int i = 0 ; i < 26 ; i++) alpha[i] = 0;
            int cc = 0;
            for (int j = 0; j < sz; j++)
            {
                if (mask & (1 << j))
                {
                    alpha[v[j] - 'a'] = true;
                    cc++;
                }
            }
            if (cc > k) continue;
            // string s = "";
            int ans2 = 0LL;
            int len = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i] or alpha[a[i] - 'a'] == true)
                {
                    len++;
                }
                else
                {
                    ans2 += len*(len+1) / 2;
                    len = 0;
                }
            }
            ans2 += len*(len+1) / 2;
        //     int i = 0;
            
        //     while (i < n)
        //     {
        //         if (s[i] == b[i])
        //         {
        //             int cnt = 0;
        //             while (i < n && s[i] == b[i])
        //             {
        //                 cnt++;
        //                 i++;
        //             }
        //             ans2 = ans2 + ((cnt) * (cnt + 1)) / 2LL;
        //         }
        //         else
        //         {
        //             i++;
        //         }
        //     }
            ans = max(ans, ans2);
        }
        cout << ans << endl;
    }
};

int32_t main()
{
    // auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        Solution A;
        A.solve();
    }
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double, milli> elapsed = end - start;
    // cout << "Execution time: " << elapsed.count() << " msec" << endl;
    return 0;
}