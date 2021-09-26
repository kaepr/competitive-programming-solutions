#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>

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

/*

(x, y)
(point.first, point.second)

*/

ll get_cross_product(pll a, pll b) {
	return a.F * b.S - b.F * a.S;
}

pll normalize_point(pll a, pll b) {
	pll res;
	res.F = a.F - b.F;
	res.S = a.S - b.S;
	return res;
}

ll get_orientation(pll a, pll b, pll c) {
	pll p1 = normalize_point(b, a);
	pll p2 = normalize_point(c, a);
	ll cross_product = get_cross_product(p1, p2);

	// cross product = 0 implies its collinear

	if (cross_product < 0) {
		cross_product = -1; // point is towards right of line segment
	} else if (cross_product > 0) {
		cross_product = 1; // point is left of line segment
	}
	return cross_product;
}

void print_point(pll a) {
	cout << "Point\n";
	cout << a.F << " " << a.S << "\n";
}

ll get_quad(pll pt) {
	if (pt.F >= 0 && pt.S >= 0) {
		return 1;
	}

	if (pt.F <= 0 && pt.S >= 0) {
		return 2;
	}

	if (pt.F <= 0 && pt.S <= 0) {
		return 3;
	}

	return 4;
}

vpll get_clockwised_pts(vpll hull) {
	vpll ans;
	pll center;
	center.F = 0;
	center.S = 0;
	ll n = hull.size();

	for (ll i = 0; i < n; i++) {
		center.F += hull[i].F;
		center.S += hull[i].S;
		hull[i].F *= n;
		hull[i].S *= n;
	}

	sort(hull.begin(), hull.end(), [&center](auto x, auto y) {

		pll p1 = make_pair(x.F - center.F, x.S - center.S);
		pll p2 = make_pair(y.F - center.F, y.S - center.S);

		ll quad1 = get_quad(p1);
		ll quad2 = get_quad(p2);

		if (quad1 != quad2) {
			return quad1 < quad2;
		}

		return p1.S * p2.F < p2.S * p1.F;
	});

	for (ll i = 0; i < n; i++) {
		pll pt = make_pair(hull[i].F / n, hull[i].S / n);
		hull[i] = pt;
		ans.push_back(hull[i]);
	}

	return ans;
}

vpll get_convex_hull_brute(vpll pts) {
	ll sz = pts.size();
	if (sz <= 2) {
		return get_clockwised_pts(pts);
	}

	vpll hull;
	map<pll, ll> mp;

	// for (ll i = 0; i < sz; i++) {
	// 	for (ll j = i + 1; j < sz; j++) {
	// 		ll to_left = 0, to_right = 0, on_line = 0;
	// 		for (ll k = 0; k < sz; k++) {
	// 			if (i != k && j != k) {
	// 				ll cp = get_orientation(pts[i], pts[j], pts[k]);
	// 				if (cp == 0) {
	// 					on_line++;
	// 				} else if (cp > 0) {
	// 					to_left++;
	// 				} else {
	// 					to_right++;
	// 				}
	// 			}
	// 		}

	// 		ll req = sz - 2 - on_line;
	// 		if (to_left == req  || to_right == req) {
	// 			mp[pts[i]]++;
	// 			mp[pts[j]]++;
	// 		}
	// 	}
	// }

	for (ll i = 0; i < sz; i++) {
		for (ll j = i + 1; j < sz; j++) {
			ll to_left = 0, to_right = 0, on_line = 0;
			ll req = sz - 2;

			for (ll k = 0; k < sz; k++) {

				ll cp = get_orientation(pts[i], pts[j], pts[k]);

				if (cp <= 0) {
					to_right++;
				}

				if (cp >= 0) {
					to_left++;
				}
			}

			if (sz  == to_left || sz == to_right) {
				mp[pts[i]]++;
				mp[pts[j]]++;
			}

			// ll req = sz - 2 - on_line;
			// if (to_left == req  || to_right == req) {
			// 	mp[pts[i]]++;
			// 	mp[pts[j]]++;
			// }

			// for (ll k = 0; k < sz; k++) {
			// 	if (i != k && j != k) {
			// 		ll cp = get_orientation(pts[i], pts[j], pts[k]);
			// 		if (cp == 0) {
			// 			on_line++;
			// 		} else if (cp > 0) {
			// 			to_left++;
			// 		} else {
			// 			to_right++;
			// 		}
			// 	}
			// }
		}
	}

	for (auto x : mp) {
		hull.push_back(x.first);
	}

	return get_clockwised_pts(hull);
}

double get_y_intercept(pll a, pll b, double x_coordinate) {
	ll X = b.first  - a.first;
	ll Y = b.second  - a.second;

	if (X == 0) {
		return ((Y / 2.0) * 1.0);
	}

	double val = Y * (x_coordinate -  a.first) * 1.0 + a.second * X * 1.0;
	val = val / (X * 1.0);
	return val;
}

void print_points(vpll a) {
	cout << "Points => \n";
	for (auto x : a) {
		cout << x.first << " " << x.second << "\n";
	}
}

vpll merge(vpll h1, vpll h2) {
	ll sz1 = h1.size(), sz2 = h2.size();

	// find upper tangents
	// pll upper_pt_h1, lower_pt_h2, upper_pt_h2, lower_pt_h2;

	double mid_x_pt = (h1[sz1 - 1].first + h2[0].first) / (2 * 1.0);
	// (mid_x_pt, y) is the middle line

	trace(mid_x_pt);

	ll h1_upper_ind = sz1 - 1;
	ll h2_upper_ind = 0;

	// print_points(h1);
	// print_points(h2);
	trace(h1_upper_ind, h2_upper_ind);

	double cur_y = get_y_intercept(h1[h1_upper_ind], h2[h2_upper_ind], mid_x_pt);
	// cout << "hi\n";
	trace(cur_y);
	ll yes = 0;
	while (true) {
		ll next_h1_upper_ind = h1_upper_ind - 1;
		if (next_h1_upper_ind == -1) {
			next_h1_upper_ind = sz1 - 1;
		}

		ll next_h2_upper_ind = (h2_upper_ind + 1)  % sz2;

		ll y_inter_1 = get_y_intercept(h1[next_h1_upper_ind], h2[h2_upper_ind], mid_x_pt);
		ll y_inter_2 = get_y_intercept(h1[h1_upper_ind], h2[next_h2_upper_ind], mid_x_pt);

		trace(next_h1_upper_ind, h2_upper_ind);
		trace(h1_upper_ind, next_h2_upper_ind);

		trace(y_inter_1, y_inter_2);

		if (y_inter_1 > cur_y || y_inter_2 > cur_y) {
			if (y_inter_1 > y_inter_2) {
				h1_upper_ind = next_h1_upper_ind;
			} else {
				h2_upper_ind = next_h2_upper_ind;
			}
			cur_y = max(y_inter_2, y_inter_1);
		} else {
			break;
		}
	}

	ll h1_lower_ind = sz1 - 1;
	ll h2_lower_ind = 0;
	cur_y = get_y_intercept(h1[h1_lower_ind], h2[h2_lower_ind], mid_x_pt);

	while (true) {
		ll next_h1_lower_ind = (h1_lower_ind + 1) % sz1;

		ll next_h2_lower_ind = h2_lower_ind - 1;
		if (next_h2_lower_ind == -1) {
			next_h2_lower_ind = sz2 - 1;
		}

		ll y_inter_1 = get_y_intercept(h1[next_h1_lower_ind], h2[h2_lower_ind], mid_x_pt);
		ll y_inter_2 = get_y_intercept(h1[h1_lower_ind], h2[next_h2_lower_ind], mid_x_pt);

		if (y_inter_1 < cur_y || y_inter_2 < cur_y) {
			if (y_inter_1 < y_inter_2) {
				h1_lower_ind = next_h1_lower_ind;
			} else {
				h2_lower_ind = next_h2_lower_ind;
			}
			cur_y = min(y_inter_2, y_inter_1);
		} else {
			break;
		}
	}

	// merge points

	vpll merged;
	merged.push_back(h1[h1_upper_ind]);

	// move to h2 upper tangent
	ll j = h2_upper_ind;
	while (j != h2_lower_ind) {
		merged.push_back(h2[j]);
		j = (j + 1) % sz2;
	}
	merged.push_back(h2[h2_lower_ind]);

	// start from h1 lower now
	j = h1_lower_ind;
	while (j != h1_upper_ind) {
		merged.push_back(h1[j]);
		j = (j + 1) % sz1;
	}

	return merged;
}


vpll merge2(vpll h1, vpll h2) {
	// cout << "inside merge 2\n";
	ll sz1 = h1.size(), sz2 = h2.size();


	// find upper tangents
	// pll upper_pt_h1, lower_pt_h2, upper_pt_h2, lower_pt_h2;


	// rightmost x points from h1
	ll xpt_h1 = h1[0].F;
	ll h1_upper_ind = 0;

	for (ll i = 1; i < sz1; i++) {
		if (h1[i].F > xpt_h1) {
			xpt_h1 = max(xpt_h1, h1[i].F);
			h1_upper_ind = i;
		}
	}

	// leftmost x points from h2
	ll xpt_h2 = h2[0].F;
	ll h2_upper_ind = 0;
	for (ll i = 1; i < sz2; i++) {
		if (h2[i].F < xpt_h2) {
			xpt_h2 = min(xpt_h2, h2[i].F);
			h2_upper_ind = i;
		}
	}

	// (mid_x_pt, y) is the middle line

	double mid_x_pt = (xpt_h1 * 1.0 + xpt_h2 * 1.0) / (2 * 1.0);
	ll orig_h1 = h1_upper_ind, orig_h2 = h2_upper_ind;

	// print_points(h1);
	// print_points(h2);

	// trace(h1_upper_ind, h2_upper_ind);

	double cur_y = get_y_intercept(h1[h1_upper_ind], h2[h2_upper_ind], mid_x_pt);
	// cout << "hi\n";
	// trace(mid_x_pt);
	// trace(cur_y);
	ll yes = 0;
	while (true) {
		// ll next_h1_upper_ind = h1_upper_ind - 1;
		// if (next_h1_upper_ind == -1) {
		// 	next_h1_upper_ind = sz1 - 1;
		// }
		// ll next_h2_upper_ind = ( + 1)  % sz2;


		ll next_h1_upper_ind = (h1_upper_ind + 1) % sz1;

		ll next_h2_upper_ind = h2_upper_ind - 1;
		if (next_h2_upper_ind == -1) {
			next_h2_upper_ind = sz2 - 1;
		}

		// trace(next_h1_upper_ind, h2_upper_ind);
		// trace(h1_upper_ind, next_h2_upper_ind);


		ll y_inter_1 = get_y_intercept(h1[next_h1_upper_ind], h2[h2_upper_ind], mid_x_pt);
		ll y_inter_2 = get_y_intercept(h1[h1_upper_ind], h2[next_h2_upper_ind], mid_x_pt);

		// print_point(h1[next_h1_upper_ind]);
		// print_point(h2[h2_upper_ind]);

		// print_point(h1[h1_upper_ind]);
		// print_point(h2[next_h2_upper_ind]);


		// trace(y_inter_1, y_inter_2);

		if (y_inter_1 > cur_y || y_inter_2 > cur_y) {
			if (y_inter_1 > y_inter_2) {
				h1_upper_ind = next_h1_upper_ind;
			} else {
				h2_upper_ind = next_h2_upper_ind;
			}
			cur_y = max(y_inter_2, y_inter_1);
			// cout << "some value changed\n";
		} else {
			// cout << "breaks\n";
			break;
		}
	}

	// cout << "final upper position\n";
	// trace(h1_upper_ind, h2_upper_ind);
	// print_point(h1[h1_upper_ind]);
	// print_point(h2[h2_upper_ind]);

	// return h1;

	// cout << "GET LOWER COORDINATES\n";

	ll h1_lower_ind = orig_h1;
	ll h2_lower_ind = orig_h2;
	// trace(h1_lower_ind);
	// trace(h2_lower_ind);

	// print_point(h1[h1_lower_ind]);
	// print_point(h2[h2_lower_ind]);

	cur_y = get_y_intercept(h1[h1_lower_ind], h2[h2_lower_ind], mid_x_pt);
	// trace(cur_y);
	yes = 0;
	while (true) {
		// ll next_h1_lower_ind = (h1_lower_ind + 1) % sz1;

		// ll next_h2_lower_ind = h2_lower_ind - 1;
		// if (next_h2_lower_ind == -1) {
		// 	next_h2_lower_ind = sz2 - 1;
		// }

		ll next_h1_lower_ind = (h1_lower_ind - 1);
		if (next_h1_lower_ind == -1) {
			next_h1_lower_ind = sz1 - 1;
		}

		ll next_h2_lower_ind = (h2_lower_ind + 1) % sz2;
		// trace(next_h1_lower_ind, h2_lower_ind);
		// trace(h1_lower_ind, next_h2_lower_ind);

		ll y_inter_1 = get_y_intercept(h1[next_h1_lower_ind], h2[h2_lower_ind], mid_x_pt);
		ll y_inter_2 = get_y_intercept(h1[h1_lower_ind], h2[next_h2_lower_ind], mid_x_pt);

		// print_point(h1[next_h1_lower_ind]);
		// print_point(h2[h2_lower_ind]);
		// trace(y_inter_1);

		// print_point(h1[h1_lower_ind]);
		// print_point(h2[next_h2_lower_ind]);
		// trace(y_inter_2);

		if (y_inter_1 < cur_y || y_inter_2 < cur_y) {
			if (y_inter_1 < y_inter_2) {
				h1_lower_ind = next_h1_lower_ind;
			} else {
				h2_lower_ind = next_h2_lower_ind;
			}
			cur_y = min(y_inter_2, y_inter_1);

			// cout << " ------ Position changed\n";

		} else {
			// cout << " ------- BREAKS \n";
			break;
		}
		// yes++;
	}

	// cout << "yes val = " << yes << "\n";

	// cout << "final lower position\n";
	// trace(h1_lower_ind, h2_lower_ind);
	// print_point(h1[h1_lower_ind]);
	// print_point(h2[h2_lower_ind]);

	// cout << "break\n";
	// return h1;

	// merge points


	// cout << "final upper position\n";
	// trace(h1_upper_ind, h2_upper_ind);
	// print_point(h1[h1_upper_ind]);
	// print_point(h2[h2_upper_ind]);

	// cout << "final lower position\n";
	// trace(h1_lower_ind, h2_lower_ind);
	// print_point(h1[h1_lower_ind]);
	// print_point(h2[h2_lower_ind]);

	vpll merged;
	merged.push_back(h1[h1_upper_ind]);

	// move to h2 upper tangent
	ll j = h2_upper_ind;
	while (j != h2_lower_ind) {
		merged.push_back(h2[j]);
		j = (j - 1);
		if (j == -1) {
			j = sz2 - 1;
		}
	}
	merged.push_back(h2[h2_lower_ind]);

	// start from h1 lower now
	j = h1_lower_ind;
	while (j != h1_upper_ind) {
		merged.push_back(h1[j]);
		j--;
		if (j == -1) {
			j = sz1 - 1;
		}
	}

	// cout << "hi\n";
	// cout << "final merged array\n";
	// print_points(merged);

	return merged;
}


vpll optimal_convex_hull(vpll points) {
	ll sz = points.size();

	// cout << "hello 1\n";
	// return points;

	if (sz <= 6) {
		return get_convex_hull_brute(points);
	}

	// cout << "hi 2\n";

	vpll h1, h2;
	for (ll i = 0; i < sz / 2; i++) {
		h1.push_back(points[i]);
	}

	for (ll i = sz / 2; i < sz; i++) {
		h2.push_back(points[i]);
	}

	// print_points(h1);
	// print_points(h2);


	vpll hull1 = optimal_convex_hull(h1);
	vpll hull2 = optimal_convex_hull(h2);

	// print_points(hull1);
	// print_points(hull2);
	// vpll hull = merge(hull1, hull2);
	vpll hull = merge2(hull1, hull2);
	// vpll hull;

	// return points;


	return hull;
}

void solve() {

	ll n;
	cin >> n;
	vpll pts;

	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		pts.push_back(make_pair(x, y));
	}

	// sort(pts.begin(), pts.end(), [](auto x, auto y) {
	// 	if (x.F == y.F) {
	// 		return x.S < y.S;
	// 	}
	// 	return x.F < y.F;
	// });

	sort(pts.begin(), pts.end());

	vpll chull = get_convex_hull_brute(pts);
	cout << chull.size() << "\n";
	for (auto x : chull) {
		cout << x.F << " " << x.S << "\n";
	}

	// vpll chull = optimal_convex_hull(pts);
	// cout << chull.size() << "\n";
	// for (auto x : chull) {
	// 	cout << x.F << " " << x.S << "\n";
	// }
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cout << setprecision(10) << fixed;
	// cin >> t;
	while (t > 0) {
		solve();
		t--;
	}

	return 0;
}
