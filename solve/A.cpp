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

bool is_sorted(vector<ll> v) {
	for (ll i = 0; i < v.size() - 1; i++) {
		if (v[i] > v[i + 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	ll n, x;
	cin >> n >> x;
	vll v;
	vector<pair<ll, ll>> orig, fin;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.PB(x);
		orig.PB(MP(x, i));
	}

	if (is_sorted(v)) {
		cout << "YES\n";
		return;
	}

	if (x >= n) {
		cout << "NO\n";
		return;
	}

	sort(orig.begin(), orig.end());

	// for (auto x : orig) {
	// 	cout << x.F << " ";
	// }
	// cout << "\n";

	// these many elements allowed to switch from behind and forward
	ll allowed = n - x;

	for (ll i = allowed; i <= n - allowed - 1; i++) {
		if (v[i] != orig[i].F) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";

	// if (allowed >= n / 2) {
	// 	cout << "YES\n";
	// 	return;
	// }

	// vll indices;
	// for (ll i = 0; i < n; i++) {
	// 	if (orig[i].F != v[i]) {
	// 		indices.PB(orig[i].S);
	// 	}
	// }

	// for (ll i = 0; i < indices.size(); i++) {
	// 	ll x = indices[i];
	// 	if ((x < allowed || x > (n - allowed - 1)) && x < n) {
	// 		// still in range
	// 	} else {
	// 		cout << "NO\n";
	// 		return;
	// 	}
	// }

	// cout << "YES\n";

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
