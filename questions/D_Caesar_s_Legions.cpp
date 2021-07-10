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
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const int MOD = 1e8;
int n1, n2, k1, k2;
int dp[101][101][11][11];

int calc(int rem_n1, int rem_n2, int consec_n1, int consec_n2)
{
    if (rem_n1 < 0 || rem_n2 < 0)
    {
        return 0;
    }

    if (consec_n1 > k1 || consec_n2 > k2)
    {
        return 0;
    }

    if (rem_n1 == 0 && rem_n2 == 0)
    {
        return 1;
    }

    if (dp[rem_n1][rem_n2][consec_n1][consec_n2] != -1)
    {
        return dp[rem_n1][rem_n2][consec_n1][consec_n2];
    }

    int ans = 0;

    ans += calc(rem_n1 - 1, rem_n2, consec_n1 + 1, 0) % MOD;
    ans %= MOD;

    ans += calc(rem_n1, rem_n2 - 1, 0, consec_n2 + 1) % MOD;
    ans %= MOD;

    dp[rem_n1][rem_n2][consec_n1][consec_n2] = ans;

    return ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n1 >> n2 >> k1 >> k2;

    int ans = calc(n1, n2, 0, 0);

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         for (int k = 0; k < 10; k++)
    //         {
    //             for (int c = 0; c < 10; c++)
    //             {
    //                 cout << dp[i][j][k][c] << " ";
    //             }
    //         }
    //     }
    // }
    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}