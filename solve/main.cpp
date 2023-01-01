#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll powmod(ll x, ll y, ll mod) {
  ll res = 1;
  x %= mod;
  if (x == 0)
    return 0;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}

const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i]) {
      cout << "NO\n";
      return;
    }
  }

  bool can_even = true;
  bool can_odd = true;

  for (int i = 1; i < n; i++) {
    if (a[i - 1] % 2 == 0 and a[i] % 2 == 0) {
      can_even = false;
    }

    if (a[i - 1] % 2 != 0 and a[i] % 2 != 0) {
      can_odd = false;
    }
  }

  if (!can_odd and !can_even) {
    cout << "NO\n";
    return;
  }

  if (can_odd and !can_even) {
    // oeoeoeoeeoeoeoeoe
  }

  if (!can_odd and can_even) {
    // eoeoeoeoeooeoeoeoeo
  }

  // both even and odd are possible
  // eoeoeoeoeoe

  cout << "YES\n";
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

