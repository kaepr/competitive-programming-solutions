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

int n;
vi query(int r) {
	cout << "? " << r << endl;
	vi tmp;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		tmp.PB(x);
	}
	return tmp;
}

vector<int> adj[2005];
vector<int> vertices;

void solve()
{
	cin >> n;
	int cnt = 0;
	int mx = n / 2;
	bool f = false;
	int vertices_ptr = 0;
	while (cnt < 2) {
		if (cnt == 0) {
			vi tmp = query(1);
			vi tmp1, tmp2;
			for (int i = 0; i < n; i++) {
				if (tmp[i] % 2 == 0) {
					tmp1.PB(i + 1);
				} else {
					tmp2.PB(i + 1);
				}
			}

			if (tmp1.size() <= tmp2.size()) {
				for (auto x : tmp1) {
					if (x == 1) {
						f = true;
					}
					vertices.PB(x);

				}
			} else {
				for (auto x : tmp2) {
					vertices.PB(x);

				}

			}

			if (f) {
				// one is in smaller set
				for (int i = 0; i < n; i++) {
					if (tmp[i] == 1) {
						adj[1].PB(i + 1);
					}
				}
			} else {
				for (int i = 0; i < n; i++) {
					if (tmp[i] == 1) {
						adj[i + 1].PB(1);
					}
				}
			}
		} else {
			// do not repeat for 1
			for (int i = 0; i < vertices.size(); i++) {
				if (vertices[i] != 1) {
					vi tmp = query(vertices[i]);
					for (int j = 0; j < n; j++) {
						if (tmp[j] == 1) {
							if (j + 1 != 1) {
								adj[vertices[i]].PB(j + 1);
							}

						}
					}
				}
			}
		}
		cnt++;
	}

	cout << "!\n";
	int tot = 0;
	for (auto x : vertices) {
		if (tot > n - 1) {
			break;
		}
		if (adj[x].size() > 0) {
			for (auto y : adj[x]) {
				cout << x << " " << y << "\n";
				tot++;
			}
		}
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// cout << "HELLLO\n";
	int t = 1;
	// cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}