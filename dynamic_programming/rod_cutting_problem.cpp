#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
	int calc(int len, vector<int>& prices, vector<int> &dp) {
		if (len == 0) {
			return prices[len];
		}

		if (dp[len] != -1) {
			return dp[len];
		}

		int ans = INT_MIN;

		for (int cnt = 1; cnt <= len; cnt++) {
			int cur = prices[cnt] + calc(len - cnt, prices, dp);
			ans = max(ans, cur);
		}
		dp[len] = ans;
		return ans;
	}

	int cutRod(int price[], int n) {
		//code here
		vector<int> v(n + 1, 0), dp(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			v[i] = price[i - 1];
		}

		return calc(n, v, dp);
	}
};

int main() {
	return 0;
}