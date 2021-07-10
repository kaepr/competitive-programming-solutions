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

const int MOD = 1e9 + 7;

const int maxn = 2e5 + 10;

int dp[maxn][10];

int calc(int m_rem, int digit)
{

    if (m_rem == 0)
    {
        return 1;
    }

    if (dp[m_rem][digit] != -1)
    {
        return dp[m_rem][digit];
    }

    int ans = 0;

    if (digit == 9)
    {
        ans = calc(m_rem - 1, 0) % MOD;
        ans %= MOD;
        ans += calc(m_rem - 1, 1) % MOD;
        ans %= MOD;
    }
    else
    {
        ans = calc(m_rem - 1, digit + 1) % MOD;
        ans %= MOD;
    }

    dp[m_rem][digit] = ans;
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;

    while (n > 0)
    {
        int dig = n % 10;
        ans += (dp[m][dig] % MOD);
        ans %= MOD;
        n /= 10;
    }

    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    // calc(50, 0);
    for (int i = 0; i < 10; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < maxn; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dp[i][j] = dp[i - 1][j + 1];
        }
        dp[i][9] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}