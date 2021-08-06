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

ll powmod(ll x, ll y, ll mod)
{
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
// const int maxn = 2e5 + 5;
// vector<int> adj[maxn];
int n, m, q;
// vector <set<int>> adj2;
map<int, set<int>> adj2;

bool isVulnerable(int num) {
	if (adj2[num].size() == 0) {
		return false;
	}

	auto it = adj2[num].end();
	it--;
	if (*it > num) {
		return true;
	} else {
		return false;
	}
}
void solve()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		adj2[i].insert(0);
	}

	for (int i = 1; i <= n; i++) {
		adj2[i].erase(0);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		// adj[x].PB(y);
		// adj[y].PB(x);
		adj2[x].insert(y);
		adj2[y].insert(x);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (isVulnerable(i)) {
			cnt++;
		}
	}

	cin >> q;
	while (q > 0) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y;

			int p1 = 0, p2 = 0;
			if (isVulnerable(x)) {
				p1++;
			}
			if (isVulnerable(y)) {
				p2++;
			}

			cnt -= p1;
			cnt -= p2;

			adj2[x].insert(y);
			adj2[y].insert(x);

			p1 = 0, p2 = 0;
			if (isVulnerable(x)) {
				p1++;
			}
			if (isVulnerable(y)) {
				p2++;
			}

			cnt += p1;
			cnt += p2;



		} else if (type == 2) {
			int x, y;
			cin >> x >> y;

			int p1 = 0, p2 = 0;
			if (isVulnerable(x)) {
				p1++;
			}
			if (isVulnerable(y)) {
				p2++;
			}

			cnt -= p1;
			cnt -= p2;

			adj2[x].erase(y);
			adj2[y].erase(x);

			p1 = 0, p2 = 0;
			if (isVulnerable(x)) {
				p1++;
			}
			if (isVulnerable(y)) {
				p2++;
			}

			cnt += p1;
			cnt += p2;



		} else {
			// int ans = calc(adj2);
			// cout << ans << "\n";
			cout << n - cnt << "\n";
		}
		q--;
	}
}

int main()
{
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
