#include <algorithm>
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

ll sum_digit(ll n) {
  ll sum = 0;

  while (n) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

const ll N = 2e5 + 10;
ll node[4 * N];

void update(ll v, ll tl, ll tr, ll id, ll val) {
  if (tl == id && tr == id) {
    node[v] = val;
    return;
  }

  if (id > tr || id < tl) {
    return;
  }

  ll tm = tl + (tr - tl) / 2;
  update(2 * v, tl, tm, id, val);
  update(2 * v + 1, tm + 1, tr, id, val);

  node[v] = node[2 * v + 1] + node[2 * v];
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
  if (tl > r || tr < l) {
    return 0;
  }

  if (l <= tl && tr <= r) {
    // l ... tl ... tr ... r
    //  cout << "HAPPENS\n";
    return node[v];
  }
  ll tm = tl + (tr - tl) / 2;
  ll ans = 0;
  ans += query(2 * v, tl, tm, l, r);
  ans += query(2 * v + 1, tm + 1, tr, l, r);
  return ans;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (ll i = 0; i < n; i++) {
    int val = 0;
    if (a[i] > 9) {
      val = 1;
    }
    update(1, 0, n - 1, i, (ll) val);
  }

  while (q) {
    int choice;
    cin >> choice;

    if (choice == 1) {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;

      // after some number of operations, they will all become single digit

      ll sum = query(1, 0, n - 1, l, r);
      if (sum == 0) {
        // nothing, no need to calculate again
      } else {
        for (ll i = l; i <= r; i++) {
          a[i] = sum_digit(a[i]);
          if (a[i] <= 9) {
            update(1, 0, n - 1, i, 0);
          }
        }
      }
    } else {
      ll x;
      cin >> x;
      x--;
      cout << a[x] << "\n";
    }

    q--;
  }
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
