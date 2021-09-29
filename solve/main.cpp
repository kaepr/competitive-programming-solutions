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
int n, fulfilled;

int query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	// cout.flush();
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

int get_rand_bolt_num(set<int> st) {
	vector<int> v;
	for (auto x : st) {
		v.push_back(x);
	}

	int sz = v.size();
	int random_index = (int) rand() % sz;
	return v[random_index];
}

void random_quicksort(vector<int>&ans, set<int> &nuts, set<int> &bolts) {
	if (nuts.empty() || bolts.empty()) {
		return;
	}
	if (nuts.size() == 1 && bolts.size() == 1) {
		fulfilled++;
		auto x = nuts.begin();
		auto y = bolts.begin();
		ans[*x] = *y;
		return;
	}

	if (fulfilled < n) {
		// Find partition p, and resulting sets for elements
		int bolt_chosen = get_rand_bolt_num(bolts);
		bolts.erase(bolt_chosen);

		// Partition around this bolt
		set<int> left_bolts, right_bolts, left_nuts, right_nuts;
		int correct_nut = 0;

		for (auto x : nuts) {
			int q = query(x, bolt_chosen);
			if (q == -1) {
				// nut at x'th pos is smaller than bolt at bolt chosen
				left_nuts.insert(x);
			} else if (q == 1) {
				// nut at x'th pos is larger than bolt at bolt chosen
				right_nuts.insert(x);
			} else {
				correct_nut = x; // Bolt to be placed here
			}
		}

		ans[correct_nut] = bolt_chosen;

		// Find correct arrangements for the bolts
		for (auto x : bolts) {
			int q = query(correct_nut, x);
			if (q == -1) {
				// x bolt is bigger than correct nut
				right_bolts.insert(x);
			} else if (q == 1) {
				// x bolt is smaller than correct nut
				left_bolts.insert(x);
			}
		}

		fulfilled++;
		random_quicksort(ans, left_nuts, left_bolts);
		random_quicksort(ans, right_nuts, right_bolts);
	}
}

void solve()
{
	fulfilled = 0;
	cin >> n;

	vector<int> ans(n + 1, 0);
	set<int> bolts, nuts;

	for (int i = 1; i <= n; i++) {
		bolts.insert(i);
		nuts.insert(i);
	}

	random_quicksort(ans, nuts, bolts);

	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout.flush();


}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int t = 1;
	// cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
