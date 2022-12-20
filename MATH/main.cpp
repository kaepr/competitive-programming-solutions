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

// (a*b)%c
int multiplyWithMod(int a, int b, int c) {
	int res = 0;
	while (b) {
		if (b & 1) {
			res = res + a;
			res %= c;
		}

		a += a;
		a %= c;
		b /= 2;
	}
	return res;
}

char digitToChar(int digit) {
	return digit + '0';
}

int charToDigit(char ch) {
	return ch - '0';
}

string addNumbers(string n1, string n2) {
	if (n1.length() > n2.length()) {
		swap(n1, n2);
	}

	string result = "";
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int carry = 0;
	for (int i = 0; i < n1.length(); i++) {
		int d1 = charToDigit(n1[i]);
		int d2 = charToDigit(n2[i]);
		int sum = d1 + d2 + carry;
		int output_digit = sum % 10;
		carry = sum / 10;
		result.push_back(digitToChar(output_digit));
	}

	for (int i = n1.length(); i < n2.length(); i++) {
		int d2 = charToDigit(n2[i]);
		int sum = d2 + carry;
		int output_digit = sum % 10;
		carry = sum / 10;
		result.push_back(digitToChar(output_digit));
	}

	if (carry) {
		result.push_back('1');
	}

	reverse(result.begin(), result.end());
	return result;
}

void multiply(vector<int> &a, int no, int &size) {
	int carry = 0;
	for (int i = 0; i < size; i++) {
		int product = a[i] * no + carry;
		a[i] = product % 10;
		carry = product / 10;
	}

	while (carry) {
		a[size] = carry % 10;
		carry = carry / 10;
		size = size + 1;
	}
}

void bigFactorial(int n) {
	vector<int> a(1000, 0);
	a[0] = 1;
	int size = 1;
	for (int i = 2; i <= n; i++) {
		multiply(a, i, size);
	}

	for (int i = size - 1; i >= 0; i--) {
		cout << a[i];
	}
	cout << "\n";
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << addNumbers(s1, s2) << "\n";
	bigFactorial(50);
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
