// https://leetcode.com/problems/palindromic-substrings/
// https://www.youtube.com/watch?v=XmSOWnL6T_I

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
	int countSubstrings(string s) {
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		// rows contain start
		// column contain end

		// as dp[i][j], will contain answer for
		// string ending at position at i,j


		// iterate over all possible gaps
		int ans = 0;
		for (int gap = 0; gap < n; gap++) {
			int i = 0, j = gap;
			for (; j < n; i++, j++) {
				if (gap == 0) {
					dp[i][j] = 1;
				} else if (gap == 1) {
					dp[i][j] = s[i] == s[j];
				} else {
					dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1];
				}

				ans += dp[i][j];

			}
		}
		return ans;
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