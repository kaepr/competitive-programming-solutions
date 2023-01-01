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

ll powmod(ll x, ll y) {
	ll res = 1;
	// x %= mod;
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
const int TOT = 31;
int n, q;
int par[N][TOT];
int t[N];

int get_kth_ancestor(int node, int k) {
	if (k == 0) {
		return node;
	}

	int log_val = log2(k);
	int max_power = powmod(2, log_val);
	return get_kth_ancestor(par[node][log_val], k - max_power);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}

	for (int i = 1; i <= n; i++) {
		par[i][0] = t[i];
	}

	for (int i = 1; i < TOT; i++) {
		for (int j = 1; j <= n; j++) {
			// find 2^ith ancestor of j'th node
			int p = par[j][i - 1];
			par[j][i] = par[p][i - 1];
		}
	}

	while (q > 0) {
		int x, k;
		cin >> x >> k;
		int ans = get_kth_ancestor(x, k);
		cout << ans << "\n";

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
