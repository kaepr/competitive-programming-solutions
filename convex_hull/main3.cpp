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
		cross_product = 1; // points are counter clockwise
	} else if (cross_product > 0) {
		cross_product = -1; // points are clockwise
	}
	return cross_product; // points are collinear is cross product = 0
}

double get_distance(pll a, pll b) {
	// dist(pt1,pt2) = (  (pt1.x - pt2.x)^2 + (pt1.y - pt2.y)^2  )^(1/2)
	return (a.F - b.F) * (a.F -  b.F) + (a.S - b.S) * (a.S - b.S);
}

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
		if (x.S == y.S) {
			return x.F > y.F;
		}
		return x.S < y.S;
	});

	// cout << "Sorted by Y coordinates\n";
	// for (auto x : v) {
	// 	cout << x.F << " " << x.S << "\n";
	// }

	vector<pll> ans;
	vector<pll> collinear_pts;
	ans.PB(v[0]);
	pll pt = v[0];

	sort(v.begin() + 1, v.end(), [&pt](auto a, auto b) {
		ll orientation = get_orientation(pt, a, b);
		if (orientation == 0) {
			// pts are collinear
			ll d1 = get_distance(pt, a);
			ll d2 = get_distance(pt, b);
			if (d1 <= d2) {
				return false;
			} else {
				return true;
			}
			// return d1 < d2;
		}

		if (orientation == -1) {
			return true;
		} else {
			return false;
		}
	});


	// ll index = 0;
	// vector<pll> store;
	// for (ll i = 1; i < n; i++) {
	// 	if (v[i].S != v[0].S) {
	// 		break;
	// 	} else {
	// 		store.PB(v[i]);
	// 	}
	// 	index = i;
	// }

	// sort(store.begin(), store.end());

	// ll ptr = 0;
	// for (ll i = 1; i <= index; i++) {
	// 	v[i] = store[ptr];
	// 	ptr++;
	// }

	// cout << "Sorted by polar coordiantes\n";
	// for (auto x : v) {
	// 	cout << x.F << " " << x.S << "\n";
	// }

	if (v.size() <= 2) {
		cout << v.size() << "\n";
		for (auto x : v) {
			cout << x.F << " " << x.S << "\n";
		}
		return;
	}

	stack<pll> st;
	st.push(v[0]);
	st.push(v[1]);
	// st.push(v[2]);

	for (ll i = 2; i < n; i++) {

		// cout << "Element right now is \n";
		// cout << v[i].F << " " << v[i].S << "\n";

		// cout << "Currently set is\n";
		// stack<pll> hello = st;
		// while (!hello.empty()) {
		// 	pll x = hello.top();
		// 	hello.pop();
		// 	cout << x.F << " " << x.S << "\n";
		// 	// trace(x.F, x.S);
		// }

		while (true && st.size() > 1) {
			pll elm1 = st.top();
			st.pop();
			pll elm2 = st.top();
			st.push(elm1);

			ll orientation = get_orientation(elm2, elm1, v[i]);

			// cout << "Changes\n";
			// cout << elm2.F << " " << elm2.S << "\n";
			// cout << elm1.F << " " << elm1.S << "\n";
			// cout << v[i].F << " " << v[i].S << "\n";

			// cout << "orientation : " << orientation << "\n";

			if (orientation == 1) {
				// points are clockwise
				// thus beneficial to remove current top
				st.pop();
			} else {
				break;
			}
		}
		st.push(v[i]);
	}

	cout << st.size() << "\n";
	while (!st.empty()) {
		pll pt = st.top();
		st.pop();
		cout << pt.F << " " << pt.S << "\n";
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
