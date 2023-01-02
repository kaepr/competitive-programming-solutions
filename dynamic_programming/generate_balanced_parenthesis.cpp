// https://www.learning.algozenith.com/problems/Generate-Balanced-Parenthesis---easy-version-464
//  https://leetcode.com/problems/generate-parentheses/
//  ( -> Ascii Code 40
//  ) -> Ascii Code 41
//  Lexicographic Order: comparing s and t, find the leftmost position
//  such that s[i] != t[i]. if no such position exists, the shortest strings is
//  less otherwise compare s[i] and t[i]

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

void calc(int n, int open, int close, vector<char> &v) {
  // used up all the brackets
  if (open == 0 and close == 0) {
    for (auto x : v) {
      cout << x;
    }
    cout << "\n";
    return;
  }

  // if we have a open bracket remaining, use that
  if (open > 0) {
    v.push_back('(');
    calc(n, open - 1, close, v);
    v.pop_back();
  }

  // close if still balanced, then repeat
  if (close > open) {
    v.push_back(')');
    calc(n, open, close - 1, v);
    v.pop_back();
  }
}

void solve() {
  int n;
  cin >> n;

  vector<char> v;

  // always benefical to use (
  // as it gives lexicographically shortest string
  calc(n, n / 2, n / 2, v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
