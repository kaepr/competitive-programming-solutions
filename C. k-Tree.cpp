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
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
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

ll n, k, d;
ll dp[105][105];

ll calc(ll n, ll maxTillHere)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        if (maxTillHere >= d)
        {
            return 1;
        }
        return 0;
    }

    if (dp[n][maxTillHere] != -1)
    {
        return dp[n][maxTillHere];
    }

    ll val = 0;

    for (ll i = 1; i <= k; i++)
    {
        val += calc(n - i, max(maxTillHere, i));
        val %= MOD;
    }

    val %= MOD;

    dp[n][maxTillHere] = val;
    return val;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    // dp[0][0] = 0;
    cin >> n >> k >> d;
    calc(n, 0);
    cout << dp[n][0];
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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