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

char digitToChar(int digit) {
	return digit + '0';
}

int charToDigit(char ch) {
	return ch - '0';
}

// string addNumbers(string n1, string n2) {
// 	if (n1.length() > n2.length()) {
// 		swap(n1, n2);
// 	}

// 	string result = "";
// 	reverse(n1.begin(), n1.end());
// 	reverse(n2.begin(), n2.end());



// }

void solve() {
	vector<int> v = {1, 2, 3};
	do {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
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
