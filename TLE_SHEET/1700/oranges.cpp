#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// A = number of markets (1‑indexed)
// B[i] = price to buy at market i (0‑indexed in vector)
// C[k] = {u, v, w} roads (1‑indexed markets, w = empty‑cart cost)
// D = tax factor
//
// Returns a vector res of length A, where
// res[i] = min_j ( B[j] + D * dist(j → i) )
vector<ll> cheapestOranges(int A,
                           const vector<int> &B,
                           const vector<array<int, 3>> &C,
                           int D)
{
    // Build adjacency list with taxed weights
    vector<vector<pair<int, int>>> adj(A);
    adj.reserve(A);
    for (auto &e : C)
    {
        int u = e[0] - 1, v = e[1] - 1, w = e[2];
        int cost = w * D;
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }

    // dist[i] = best cost to end up at i (buy somewhere + travel back)
    const ll INF = LLONG_MAX / 4;
    vector<ll> dist(A, INF);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<>>
        pq;

    // Multi‐source init: starting “distance” = cost to buy at each market
    for (int i = 0; i < A; i++)
    {
        dist[i] = B[i];
        pq.emplace(dist[i], i);
    }

    // Standard Dijkstra
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &[v, w] : adj[u])
        {
            ll nd = d + w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }

    return dist;
}

// Example of how you might hook it up to I/O
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, M, D;
    cin >> A >> M >> D;
    // A = markets, M = number of roads, D = tax factor
    vector<int> B(A);
    for (int i = 0; i < A; i++)
        cin >> B[i];

    vector<array<int, 3>> C(M);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        C[i] = {u, v, w};
    }

    auto res = cheapestOranges(A, B, C, D);
    for (ll x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
