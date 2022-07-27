/*
https://leetcode.com/problems/jump-game/
https://leetcode.com/problems/jump-game-ii/
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

bool canJump(vector<int>& nums) {
	int n = nums.size();
	int max_reach = 0;

	for (int i = 0; i < n; i++) {
		if (i <= max_reach) {
			max_reach = max(max_reach, i + nums[i]);
		}
	}

	return max_reach >=  n - 1;
}

class Solution {
public:
	const int INF = 1e9;
	int jump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, INF);

		// 0 jumps to reach the first position
		dp[0] = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j < n) {
					dp[i + j] = min(dp[i + j], 1 + dp[i]);
				}
			}
		}

		return dp[n - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
