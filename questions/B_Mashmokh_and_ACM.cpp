#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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

int dp[2005][2005];
int n, k;

// i = elm, k = remaining length
int sol(int i, int k)
{
    if (k <= 0)
        return 1;

    if (dp[i][k] != -1)
        return dp[i][k];

    int ans = 0;
    for (int j = i; j <= n; j += i)
    {
        // trace(j, k - 1);
        ans += (sol(j, k - 1) % MOD);
        ans %= MOD;
    }
    dp[i][k] = ans;
    dp[i][k] %= MOD;
    return dp[i][k];
}

void solve()
{
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    sol(1, k);
    // for (int i = 1; i <= n; i++)
    // {
    // sol(i, k);
    // }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[1][k] << "\n";
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