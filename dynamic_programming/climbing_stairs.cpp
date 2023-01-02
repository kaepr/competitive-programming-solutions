#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int N;

// returns number of ways to N if we are level stair
int rec(int level) { // level denotes which stair currently at

  // pruning case
  if (level > N) {
    return 0;
  }

  // base case
  if (level == N) {
    return 1;
  }

  int ans = 0;

  // loop over choices
  for (int step = 1; step <= 3; step++) {

    // Check if move is valid
    if (level + step <= N) {
      int ways = rec(level + step);
      ans += ways;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  int ans = rec(0);

  cout << ans << "\n";

  return 0;
}
