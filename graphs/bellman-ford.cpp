#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

/*
Bellman Ford Algorithm

   for |V| - 1
        relax all edges

This question is a modified bellman ford algo
https://www.learning.algozenith.com/problems/Bellaman-Ford-Revisited-194
*/

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct edge {
    ll u, v, w;
};

ll n, m, v;

void solve() {
    cin >> n >> m;

    vector<edge> edges;
    vector<ll> dist(n + 1, INF);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge e = {};
        e.u = a;
        e.v = b;
        e.w = -c;
        edges.push_back(e);
    }

    dist[1] = 0;

    for (ll i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            dist[edges[j].v] =
                min(dist[edges[j].v], dist[edges[j].u] + edges[j].w);
        }
    }

    bool neg = false;
    for (int j = 0; j < m; j++) {
        if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w) {
            neg = true;
            dist[edges[j].v] =
                min(dist[edges[j].v], dist[edges[j].u] + edges[j].w);
        }
    }

    if (neg) {
        cout << -1 << "\n";
        return;
    }

    cout << -1 * dist[n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
