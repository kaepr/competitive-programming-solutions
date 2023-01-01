#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

ll powmod(ll x, ll y) {
	ll res = 1;
	if (x == 0)
		return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res;
}

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 31;
int par[N][LOG];
bool vis[N];
int depth[N];
vector<int> adj[N];
int n, q;

void dfs(int node, int parent, int d) {
	vis[node] = true;
	par[node][0] = parent;
	depth[node] = d;

	for (auto child : adj[node]) {
		if (!vis[child]) {
			dfs(child, node, d + 1);
		}
	}
}

int get_kth_ancestor(int node, int k) {
	if (k == 0) {
		return node;
	}

	for (int i = 30; i >= 0; i--) {
		if (k & (1 << i)) {
			return get_kth_ancestor(par[node][i], k - (1 << i));
		}
	}

	return node;
}

int get_lca(int a, int b) {
	// always have depth a < depth b
	// if not swap them
	if (depth[a] > depth[b]) {
		swap(a, b);
	}

	int diff = depth[b] - depth[a];

	b = get_kth_ancestor(b, diff);

	if (a == b) {
		return a;
	}

	for (int i = LOG - 1; i >= 0; i--) {
		int x = par[a][i];
		int y = par[b][i];
		if (x != 0 and y != 0 and x != y) {
			a = x;
			b = y;
		}
	}

	return par[a][0];
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].PB(y);
		adj[y].PB(x);
	}

	// parent of 0 is 0 itself
	par[0][0] = 0;

	// root tree at 1
	dfs(1, 0, 1);

	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}

	while (q > 0) {
		int x, y;
		cin >> x >> y;

		int lca = get_lca(x, y);
		int dist = depth[x] + depth[y] - 2 * depth[lca];
		cout << dist << "\n";

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

/*
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
const int N = 3e5 + 5;
const int LOG = 31;
int n, q;
vector<int> adj[N];
int par[N][LOG];
int depth[N];
bool vis[N];

void dfs(int node, int parent, int level) {
    vis[node] = true;
    par[node][0] = parent;
    depth[node] = level;

    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, node, level + 1);
        }
    }
}

int get_kth_ancestor(int node, int k) {
    if (k == 0) {
        return node;
    }

    for (int i = 30; i >= 0; i--) {
        if (k & (1 << i)) {
            return get_kth_ancestor(par[node][i], k - (1 << i));
        }
    }

    return node;
}

int get_lca(int a, int b) {
    // always have depth a < depth b
    // if not swap them
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    int diff = depth[b] - depth[a];
    b = get_kth_ancestor(b, diff);

    // trace(a, b, diff);

    if (a == b) {
        return a;
    }


    for (int i = LOG - 1; i >= 0; i--) {
        int x = par[a][i];
        int y = par[b][i];

        if (x != 0 and y != 0 and x != y) {
            a = x;
            b = y;
        }

        // trace(a, b);
    }

    return par[a][0];
}


void solve() {
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    // parent of 0 is 0
    par[0][0] = 0;

    dfs(1, 0, 1);

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

    cin >> q;
    while (q > 0) {
        int start, end, energy;
        cin >> start >> end >> energy;
        int lca = get_lca(start, end);
        int dist = depth[start] + depth[end] - 2 * depth[lca];
        // trace(start, end, dist, lca);

        if (energy >= dist) {
            cout << end << "\n";
        } else {
            int ds = depth[start];
            int dist_lca = depth[lca];
            int de = depth[end];

            // cost to go up
            int c1 = ds - dist_lca;
            if (energy <= c1) {
                cout << get_kth_ancestor(start, energy) << "\n";
            } else {
                int dist_branch = de - dist_lca + 1;
                energy -= c1;
                cout << get_kth_ancestor(end, dist_branch - energy - 1) << "\n";
            }
        }
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

*/