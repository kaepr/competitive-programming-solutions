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

ll dfs(
    ll node,
    vector<vector<ll>> &adj,
    vector<bool> &vis,
    vector<ll> &gcd,
    vector<ll> &val)
{
	vis[node] = true;
	if (adj[node].size() == 1) {
		// its a leaf node
		gcd[node] = val[node];
		return gcd[node];
	}

	ll g = val[node];
	for (auto child : adj[node]) {
		if (!vis[child]) {
			g = __gcd(g, dfs(child, adj, vis, gcd, val));
		}
	}

	gcd[node] = g;
	return g;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> adj(n + 1);
	vector<ll> v(n + 1, 0);

	for (ll i = 1; i <= n - 1; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].PB(y);
		adj[y].PB(x);
	}

	for (ll i = 1; i <= n; i++) {
		cin >> v[i];
	}

	// for (ll i = 1; i <= n; i++) {
	// 	trace(i);
	// 	for (auto x : adj[i]) {
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<ll> gcd(n + 1, 0);
	vector<bool> vis(n + 1, false);

	dfs(1, adj, vis, gcd, v);

	// for (ll i = 1; i <= n; i++) {
	// 	cout << gcd[i] << " ";
	// }
	// cout << "\n";

	ll mx = -1e9;
	for (ll i = 1; i <= n; i++) {
		ll sum = 0;
		for (auto x : adj[i]) {
			sum += gcd[x];
		}
		// trace(i, sum);
		if (adj[i].size() > 1) {
			mx = max(mx, sum + gcd[i]);
		} else {
			mx = max(sum, mx);
		}
	}

	cout << mx << "\n";
}

int main() {
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
