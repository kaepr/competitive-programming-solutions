#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define fst first
#define snd second

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
const ll INF = 1e18;

ll N, W;
ll dp[105][100005];
ll values[105];
ll wts[105];

ll rec(ll idx, ll cur) {
    if (cur < 0) {
        return -INF;
    }

    if (idx == N) {
        return 0;
    }

    if (dp[idx][cur] != -1) {
        return dp[idx][cur];
    }

    // don't take current item
    ll ans = rec(idx + 1, cur);

    // take current item and move
    ans = max(ans, values[idx] + rec(idx + 1, cur - wts[idx]));

    dp[idx][cur] = ans;
    return ans;
}

void solve() {
    cin >> N >> W;

    memset(dp, -1, sizeof(dp));

    for (ll i = 0; i < N; i++) {
        cin >> wts[i] >> values[i];
    }

    cout << rec(0, W) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
