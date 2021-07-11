#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

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

int powmod(int x, int y, int mod)
{
	int res = 1;
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

const int MOD = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> st1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st1.insert(a[i]);
	}

	if (st1.size() == 1) {
		cout << 0 << "\n";
		return;
	}

	int steps = 1;

	while (true) {
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			b[i] = __gcd(a[i], a[(i + 1) % n]);
		}

		set<int> st;
		for (auto x : b) {
			st.insert(x);
		}

		if (st.size() == 1) {
			break;
		}

		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
		steps++;
	}

	cout << steps << "\n";
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
