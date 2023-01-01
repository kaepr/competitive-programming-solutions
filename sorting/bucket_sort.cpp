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

void solve()
{
	ll n, b;
	cin >> n >> b;
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.PB(x);
	}

	vector<ll> buckets[b];

	ll mx = *max_element(v.begin(), v.end());
	ll mn = *min_element(v.begin(), v.end());

	ll range = (mx - mn + 1) / b;
	ll sz = range / b;

	for (ll i = 0; i < n; i++) {
		ll index = (v[i] - mn) / range;
		buckets[index].PB(v[i]);
	}

	for (ll i = 0; i < b; i++) {
		ll sz = buckets[i].size();
		cout << sz << " ";
		sort(buckets[i].begin(), buckets[i].begin() + sz);
		for (auto x : buckets[i]) {
			cout << x << " ";
		}
		cout << "\n";
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