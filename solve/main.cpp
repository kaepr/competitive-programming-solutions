#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
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
const ll INF = 1e18;

ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<bool> vis;
vector<ll> dist;
double ans = 0;

void bfs(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        ll u = cur.snd;
        ll cur_d = cur.fst;

        if (vis[u]) {
            continue;
        }

        vis[u] = true;

        for (auto x : g[cur.snd]) {
            ll v = x.fst;
            int w = x.snd;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        auto u = i;
        for (auto x : g[u]) {
            auto v = x.fst;
            auto w = x.snd;

            if (dist[u] <= dist[v]) {
                // technically only == will work
                // orelse fire would have reached through v anyways
                // basically
                // u -- (w) --> v
                // is the best path the burning could take
                if (dist[v] - dist[u] >= w) {
                    ans = max(ans, (double)dist[u] + w);
                } else {
                    // the path from u --> v was not the best
                    // both started burning
                    // this means it has started burning at both ends
                    // they will meet at some point
                    // calculate that point
                    double d = (1.0 * dist[u] + dist[v] + w) / 2.0;
                    ans = max(ans, d);
                }
            }
        }
    }
}

void solve() {
    ans = 0;

    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, false);
    dist.assign(n + 1, INF);

    while (m) {
        ll u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
        m--;
    }

    ll start;
    cin >> start;
    bfs(start);

    // for (ll i = 1; i <= n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << "\n";

    cout << (ll)(ans * 10) << "\n";
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
