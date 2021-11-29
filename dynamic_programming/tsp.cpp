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

int tsp(vector<vector<int>> &dist, int setOfCities, int city, int n, vector<vector<int>> &dp) {
	if (setOfCities == (1 << n) - 1) {
		// return cost from the city to the original
		return dist[city][0];
	}

	if (dp[setOfCities][city] != -1) {
		return dp[setOfCities][city];
	}

	// otherwise try all possibilites
	int ans = INT_MAX;
	for (int choice = 0; choice < n; choice++) {
		if (!(setOfCities & (1 << choice))) {
			int subProb = dist[city][choice] + tsp(dist, setOfCities | (1 << choice), choice, n, dp);
			ans = min(ans, subProb);
		}
	}

	dp[setOfCities][city] = ans;
	return ans;
}

void solve() {
	vector<vector<int>> dist = {
		{0, 20, 42, 25},
		{20, 0, 30, 34},
		{42, 30, 0, 10},
		{25, 34, 10, 0}
	};
	int n = 4;

	vector<vector<int>> dp(1 << n, vector<int>(n, -1));

	cout << tsp(dist, 1, 0, n, dp) << "\n";
}

int main() {
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
