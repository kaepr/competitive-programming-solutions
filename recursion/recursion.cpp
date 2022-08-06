#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int countSubsetsEqualToX(vector<int> &arr, int n, int i, int X) {
	if (i == n) {
		if (X == 0) {
			return 1;
		}
		return 0;
	}

	int inc = countSubsetsEqualToX(arr, n, i + 1, X - arr[i]);
	int exc = countSubsetsEqualToX(arr, n, i + 1, X);
	return inc + exc;
}



int main() {

	string s = "abcd";
	vector<string> v;

	for (int idx = 0; idx < s.length(); idx ++) {
		string tmp = "";
		for (int j = idx; j < s.length(); j++) {
			tmp += s[j];
			v.push_back(tmp);
		}
	}

	for (auto x : v) {
		cout << x << "\n";
	}


	return 0;
}










