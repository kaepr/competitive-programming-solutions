#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define endl '\n'
#define int long long
#define All(x) x.begin(), x.end()

#define Exit(x)                                                                \
  {                                                                            \
    cout << x << endl;                                                         \
    return;                                                                    \
  }
#define Yes                                                                    \
  {                                                                            \
    cout << "Yes" << endl;                                                     \
    return;                                                                    \
  }
#define No                                                                     \
  {                                                                            \
    cout << "No" << endl;                                                      \
    return;                                                                    \
  }
using namespace std;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10, M = 1e6 + 10;

int n, m, q;
int a[N], b[N];
bool st[N];
vector<int> prime;
void getPrimes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i])
      prime.push_back(i);
    for (int j = 0; prime[j] <= n / i; j++) {
      st[prime[j] * i] = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int num = a[i];
    for (int p : prime) {
      if (p * p > num)
        break;
      if (num % p == 0) {
        while (num % p == 0)
          num /= p;
        mp[p]++;
        if (mp[p] >= 2)
          Yes
      }
    }

    if (num > 1)
      mp[num]++;
    if (mp[num] >= 2)
      Yes
  }
  No
}

signed main() {
  int T = 1;
  getPrimes(N);
  cin >> T;
  while (T--)
    solve();
  return 0;
}
