#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args &&...args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod) {
    int res = 1;
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

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    ll ans = 0;
    ll n = s.length();

    ll dp[n][2];
    // memset(dp, 0, sizeof(dp));

    if (s[0] == '?') {
        dp[0][0] = 1, dp[0][1] = 1;
    }
    else if (s[0] == '1') {
        dp[0][1] = 1, dp[0][0] = 0;
    }
    else if (s[0] == '0') {
        dp[0][1] = 0, dp[0][0] = 1;
    }

    for (ll i = 1; i < n; i++) {
        if (s[i] == '?') {
            dp[i][0] = 1 + dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        }
        else if (s[i] == '1') {
            dp[i][1] = 1 + dp[i - 1][0];
            dp[i][0] = 0;
        }
        else if (s[i] == '0') {
            dp[i][0] = 1 + dp[i - 1][1];
            dp[i][1] = 0;
        }
    }

    for (ll i = 0; i < n; i++) {
        ans += max(dp[i][0], dp[i][1]);
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }

    return 0;
}