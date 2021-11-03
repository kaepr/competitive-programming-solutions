// https://leetcode.com/problems/unique-binary-search-trees/
// catalan number

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}

		return dp[n];
	}
};

void solve() {

}

int main() {

	int t = 1;
	cin >> t;
	while (t > 0) {
		solve();
		t--;
	}

	return 0;
}