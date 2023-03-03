#include <bits/stdc++.h>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vll = vector<long long>;

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

vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_end, cycle_start;

bool dfs(int node, int par) {
    color[node] = 2;

    for (auto neighbor : adj[node]) {
        if (neighbor == par)
            continue;

        if (color[neighbor] == 1) {
            // not visited
            parent[neighbor] = node;

            if (dfs(neighbor, parent[neighbor])) {
                return true;
            }

        } else if (color[neighbor] == 2) {
            // found back edge, hence cycle exists
            cycle_end = node;
            cycle_start = neighbor;
            return true;
        } else {
            // color 3, nothing happens
        }
    }

    color[node] = 3;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    color.assign(n + 1, 1);
    parent.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 1 and dfs(i, parent[i])) {
            break;
        }
    }

    if (cycle_start != -1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // print cycle code
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
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
