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

bool isPalindrome(string s) {
	ll n = s.length();
	for (ll i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			return false;
		}
	}
	if (s.length() > 0) {
		return true;
	}
	return false;
}

ll getIndex(string tmp, string s, ll pos) {
	ll sz = tmp.length();
	char midChar = tmp[pos];
	ll f = 0;
	for (ll i = 0; i <= pos ; i++) {
		if (tmp[i] == midChar) {
			f++;
		}
	}

	ll n = s.length();

	for (ll i = 0; i < n; i++) {
		if (s[i] == midChar) {
			f--;
			if (f <= 0) {
				return i;
			}
		}
	}
	return 0;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<char> st;

	for (int i = 0; i < n; i++) {
		st.insert(s[i]);
	}

	int cost = 1e9;
	bool f = false;

	for (auto toDelete : st) {

		int left = 0, right = n - 1;
		int deleted = 0;
		bool notFound = false;
		while (left < right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			} else if (s[left] == toDelete and s[left] != s[right]) {
				left++;
				deleted++;
			} else if (s[right] == toDelete and s[right] != s[left]) {
				right--;
				deleted++;
			} else {
				notFound = true;
				break;
			}
		}

		if (!notFound) {
			cost = min(cost, deleted);
			f = true;
		}
	}

	if (f) {
		cout << cost << "\n";
	} else {
		cout << -1 << "\n";
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
		solve();
		t--;
	}

	return 0;
}
