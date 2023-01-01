#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

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
const ll N = 3e5 + 5;
const ll LOG = 31;
vector<pair<ll, ll>> adj[N];
ll par[N][LOG];
ll minWts[N][LOG];
ll wts[N];
ll depth[N];
ll vis[N];
ll n, m, q;

void dfs(ll node, ll parent, ll lvl, ll edge_wt) {
    vis[node] = true;
    par[node][0] = parent;
    minWts[node][0] = edge_wt;
    wts[node] = edge_wt;
    depth[node] = lvl;

    for (auto child : adj[node]) {
        if (!vis[child.F]) {
            dfs(child.F, node, lvl + 1, child.S);
        }
    }
}

ll get_kth_ancestor(ll node, ll k) {
    if (k == 0) {
        return node;
    }

    for (ll i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            return get_kth_ancestor(par[node][i], k - (1 << i));
        }
    }
    return node;
}


ll get_min_w_ancestor(ll node, ll k) {
    if (k == 0) {
        return INT_MAX;
    }

    for (ll i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            ll mn = minWts[node][i];
            return min(mn, get_min_w_ancestor(par[node][i], k - (1 << i)));
        }
    }
    return INT_MAX;
}

ll get_lca(ll a, ll b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    b = get_kth_ancestor(b, depth[b] - depth[a]);

    if (a == b) {
        return a;
    }

    for (ll i = LOG - 1; i >= 0; i--) {
        ll x = par[a][i];
        ll y = par[b][i];
        if (x != 0 and y != 0 and x != y) {
            a = x;
            b = y;
        }
    }

    return par[a][0];
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].PB(MP(v, wt));
        adj[v].PB(MP(u, wt));
    }

    par[0][0] = 0;
    dfs(1, 0, 1, INT_MAX);

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 1; j <= n; j++) {
            int parent = par[j][i - 1];
            par[j][i] = par[parent][i - 1];
            minWts[j][i] = min(minWts[j][i - 1], minWts[parent][i - 1]);
        }
    }

    cin >> q;
    while (q > 0) {
        ll a, b;
        cin >> a >> b;
        ll lca = get_lca(a, b);

        ll d1 = depth[a] - depth[lca];
        ll d2 = depth[b] - depth[lca];

        // trace(d1, d2, a, b);

        ll wt1 = INT_MAX, wt2 = INT_MAX;

        wt1 = get_min_w_ancestor(a, d1);
        wt2 = get_min_w_ancestor(b, d2);
        // trace(wt1, wt2);

        cout << min(wt1, wt2) << "\n";

        q--;
    }

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
