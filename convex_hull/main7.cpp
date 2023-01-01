#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define pii pair<int,int>
#define pll pair<long long, long long>
#define PB push_back
#define F first
#define S second
#define MP make_pair

/*
pair<first, second>
<x,y>
a.F, a.S
*/

ll get_orientation(pll a, pll b, pll c) {

	ll cross_product = ((b.F - a.F) * (c.S - a.S)) - ((b.S - a.S) * (c.F - a.F));

	if (cross_product < 0) {
		cross_product = -1; // points are clockwise
	} else if (cross_product > 0) {
		cross_product = 1; // points are counter clockwise
	}
	return cross_product; // points are collinear is cross product = 0
}

// double get_distance(pll a, pll b) {
// 	// dist(pt1,pt2) = (  (pt1.x - pt2.x)^2 + (pt1.y - pt2.y)^2  )^(1/2)
// 	return (a.F - b.F) * (a.F -  b.F) + (a.S - b.S) * (a.S - b.S);
// }

void solve()
{
	ll n;
	cin >> n;
	vector<pll> v;

	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.PB(MP(x, y));
	}

	sort(v.begin(), v.end(), [&](auto x, auto y) {
		if (x.F == y.F) {
			return x.S < y.S;
		}
		return x.F < y.F;
	});

	// cout << "Sorted by X coordinates\n";
	// for (auto x : v) {
	// 	cout << x.F << " " << x.S << "\n";
	// }

	if (n < 3) {
		cout << n << "\n";
		for (auto x : v) {
			cout << x.F << " " << x.S << "\n";
		}
		return;
	}

	vector<pll> ans;

	ll ptr = 0;

	for (ll i = 0; i < n; i++) {
		while (true) {
			ptr = ans.size();
			if (ptr > 1) {
				ll orientation = get_orientation(ans[ptr - 2], ans[ptr - 1], v[i]);
				if (orientation < 0LL) {
					ans.pop_back();
				} else {
					break;
				}
			} else {
				break;
			}
		}

		ans.push_back(v[i]);
	}

	ll len = ans.size();

	for (ll i = n - 2; i >= 0; i--) {

		while (true) {
			ll sz = ans.size();
			if (sz > len) {
				ll orientation = get_orientation(ans[sz - 2], ans[sz - 1], v[i]);
				if (orientation < 0LL) {
					ans.pop_back();
				} else {
					break;
				}
			} else {
				break;
			}
		}

		ans.PB(v[i]);
	}

	set<pll> st;
	for (auto x : ans) {
		st.insert(x);
	}

	cout << st.size() << "\n";
	for (auto x : st) {
		cout << x.F << " " << x.S << "\n";
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
