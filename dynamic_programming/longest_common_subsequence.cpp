// https://www.learning.algozenith.com/problems/LCS-of-3-Strings-900

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int dp[105][105][105];
string s1, s2, s3;
int n, m, l;

// LCS of three strings
// rec(i, j, k) gives us the best LCS from s1[i..N], s2[j..M], s3[k..s3.len()]
int rec(int i, int j, int k) {
  if (i >= n or j >= m or k >= l) {
    return 0;
  }

  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }

  int ans = 0;

  if (s1[i] == s2[j] and s2[j] == s3[k]) {
    ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
  }

  ans = max(ans, rec(i + 1, j, k));
  ans = max(ans, rec(i, j + 1, k));
  ans = max(ans, rec(i, j, k + 1));

  dp[i][j][k] = ans;
  return ans;
}

void solve() {
  cin >> s1 >> s2 >> s3;

  n = s1.length();
  m = s2.length();
  l = s3.length();

  memset(dp, -1, sizeof(dp));

  int ans = rec(0, 0, 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }

  return 0;
}

