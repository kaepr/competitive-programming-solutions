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
ll xr, cnt;

ll dfs(ll parent, vector<vector<ll>> &adj, vector<ll> &arr, vector<ll> &vis) {
	vis[parent] = true;

	ll cur_xor = arr[parent];

	for (auto child : adj[parent]) {
		if (!vis[child]) {
			cur_xor ^= dfs(child, adj, arr, vis);
		}
	}

	if (cur_xor == xr) {
		cnt++;
		cur_xor = 0;
	}

	return cur_xor;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	// trace(n, k);
	// cout << "n,k" << n << " " << k << "\n";
	xr = 0, cnt = 0;
	vll arr(n + 1);

	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		xr ^= arr[i];
	}

	// for (ll i = 1; i <= n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << "\n";

	vector<vector<ll>> adj(n + 1);
	vll vis(n + 1, 0);

	for (ll i = 1; i <= n - 1; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].PB(y);
		adj[y].PB(x);
	}

	// trace(xr, k);

	if (xr == 0) {
		cout << "YES\n";
		return;
	}

	if (k <= 2) {
		cout << "NO\n";
		return;
	}

	dfs(1, adj, arr, vis);
	// trace(xr, cnt);

	if (cnt >= 2) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

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

		// cout << "hello\n";
		solve();
		t--;
	}

	return 0;
}
