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

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int getIthBit(int n, int i) {
	int mask = (1 << i);
	return (n & mask) > 0 ? 1 : 0;
}

int clearIthBit(int n, int i) {
	int mask = ~(1 << i);
	n = n & mask;
	return n;
}

int setIthBit(int n, int i) {
	int mask = (1 << i);
	n = n | mask;
	return n;
}

int updateIthBit(int n, int i, int v) {
	clearIthBit(n, i);
	int mask = (v << i);
	n = n | mask;
	return n;
}

int clearLastIBits(int n, int i) {
	int mask = ((-1) << i);
	n = n & mask;
	return n;
}


int clearBitsInRange(int n, int i, int j) {
	int a = (~0) << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;
	return n;
}

// replace bits in N by M, from pos i to j
int replaceBitsInNbyM(int n, int i, int j, int m) {
	n = clearBitsInRange(n, i, j);
	int mask = (m << i);
	return n | mask;
}

bool isPowerOfTwo(int n) {
	if (n and !(n & (n - 1))) {
		return true;
	} else {
		return false;
	}
}


bool isPowerOfFour(int n) {
	if (isPowerOfTwo(n)) {
		n = n - 1;
		int cnt = __builtin_popcount(n);
		if (cnt % 2 == 0) {
			return true;
		}
	}

	return false;
}

int countSetBits(int n) {
	int cnt = 0;

	while (n > 0) {
		cnt += (n & 1);
		n = n >> 1;
	}

	return cnt;
}

int count_bits_hack(int n) {
	int ans = 0;
	while (n > 0) {
		// removes last set from current number
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int convertToBinary(int n) {
	int ans = 0, p = 1;
	while (n > 0) {
		int last_bit = n & 1;
		ans += p * last_bit;
		p *= 10;
		n = n >> 1;
	}
	return ans;
}

vector<int> sortByBits(vector<int>& arr) {
	sort(arr.begin(), arr.end(), [](int x, int y) {
		int c1 = countSetBits(x), c2 = countSetBits(y);
		if (c1 > c2) {
			return true;
		} else if (c2 > c1) {
			return false;
		} else {
			return x < y;
		}
	});
	return arr;
};

int hammingDistance(int x, int y) {
	int diff = 0;

	while (x > 0 or y > 0) {
		int lb1 = x & 1, lb2 = y & 1;
		if (lb1 != lb2) {
			diff++;
		}
		x = x >> 1;
		y = y >> 1;
	}

	return diff;
}

void printAllSubsets(vector<int> arr) {
	int n = arr.size();
	vector<vector<int>> ans;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				tmp.push_back(arr[j]);
			}
		}
		ans.push_back(tmp);
	}
}


void solve() {
	cout << hammingDistance(1, 4) << "\n";
}

/*

https://leetcode.com/problems/single-number/
Xor of whole array, as xor of similar numbers is 0, so we can use this
to find the answer

https://leetcode.com/problems/single-number-iii/
Xor of two unique numbers > 0
A bit is set when it is present in exactly one of the two numbers
Pos any first 1 set bit ( first set bit from right )

https://leetcode.com/problems/single-number-ii/
As every number comes thrice ( except one )
If we take frequency array of bits of those numbers, then we can see that number of bits will be of form
3N or 3N + 1
Numbers having form 3N + 1, contribute that bit position to the final value


*/

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
