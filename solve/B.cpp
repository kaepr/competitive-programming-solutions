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

void solve() {
	int n, k;
	cin >> n >> k;
	// vector<int> adj(n + 1);
	// vector<bool> vis(n + 1, false);
	vector<int> leaves;
	map<int, set<int>> mp;

	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		// adj[x].PB(y);
		// adj[y].PB(x);
		mp[x].insert(y);
		mp[y].insert(x);
	}

	if (n == 1) {
		cout << 0 << "\n";
		return;
	}

	int rem = n;
	set<int> lfs;
	for (auto x : mp) {
		if (x.S.size() <= 1) {
			lfs.insert(x.F);
		}
	}

	while (k > 0) {
		if (rem <= 0) {
			break;
		}

		// find all current leaves
		// their adj size shuold be 1



		rem -= lfs.size();
		for (auto x : mp) {
			for (auto y : lfs) {
				if (x.S.find(y) != x.S.end()) {
					mp[x.F].erase(y);
				}
			}
		}

		// update maps
		for (auto y : lfs) {
			mp.erase(y);
		}

		k--;
	}


	cout << rem << "\n";
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
