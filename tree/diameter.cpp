#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;
int farthest_node = -1;
int mxDistance = 0;

void dfs(int node, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    if (dist >= mxDistance) {
        mxDistance = dist;
        farthest_node = node;
    }

    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, dist + 1, adj, vis);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<bool> vis(n + 1, false);

    dfs(1, 0, adj, vis);
    // trace(mxDistance, farthest_node);
    fill(vis.begin(), vis.end(), false);

    mxDistance = 0;
    dfs(farthest_node, 0, adj, vis);
    cout << mxDistance * 3 << "\n";

}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}
