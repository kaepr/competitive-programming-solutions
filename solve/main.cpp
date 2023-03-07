#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vll = vector<long long>;

#define fst first
#define snd second

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;

ll n, m;
vector<vector<pair<ll, int>>> g;
vector<bool> vis;
vector<ll> dist;

void solve() {
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, false);
    dist.assign(n + 1, 1e18);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        g[a].push_back(make_pair(b, c));
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;

    // distance , node
    pq.push(make_pair(0, 1));
    dist[1] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();

        ll node = cur.snd;
        ll c_dist = cur.fst;

        pq.pop();
        if (vis[node])
            continue;

        vis[node] = true;

        for (auto neighbor : g[node]) {
            if (dist[neighbor.fst] > dist[node] + neighbor.snd) {
                dist[neighbor.fst] = dist[node] + neighbor.snd;
                pq.push(make_pair(dist[neighbor.fst], neighbor.fst));
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
