// https://www.learning.algozenith.com/problems/Bricks-Colouring-170

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

ll N, M, K;
ll dp[2005][2005];

ll rec(ll lvl, ll brk) {

  // pruning
  if (brk > K || lvl > N) {
    return 0;
  }

  // base case
  if (lvl == N and brk == K) {
    return 1;
  }

  if (dp[lvl][brk] != -1) {
    return dp[lvl][brk];
  }

  ll ans = 0;

  if (lvl == 0) {
    ans = (M * rec(lvl + 1, brk)) % MOD;
  } else {
    ans = rec(lvl + 1, brk) % MOD;
    ans += ((M - 1) % MOD * (rec(lvl + 1, brk + 1) % MOD)) % MOD;
    ans %= MOD;
  }

  dp[lvl][brk] = ans;
  return ans;
}

void solve() {
  cin >> N >> M >> K;
  memset(dp, -1, sizeof(dp));

  ll ans = rec(0, 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t) {
    solve();
    t--;
  }

  return 0;
}
