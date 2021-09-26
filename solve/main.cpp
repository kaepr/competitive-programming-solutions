#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

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

int query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	char x;
	cin >> x;
	if (x == '<') {
		return -1; // Size of i'th nut is less than j'th bolt
	} else if (x == '=') {
		return 0; // i'th nut and j'th bolt match
	} else {
		return 1; // i'th nut is greater than size of j'th bolt
	}
}

void solve()
{
	int n;
	cin >> n;
	vector<int> ans(n, 0);
	int cnt = 0;
	while (cnt < 15) {

		cnt++;
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
