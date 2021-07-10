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

ll cnt = 1;
ll ans, n;
ll a[10005];
ll dp[10005];

ll solve2(ll i)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    dp[i] = max(a[i] + solve2(i - 2), solve2(i - 1));
    return dp[i];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = max(dp[1], a[2]);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
    }

    // for (int i = 0; i <= n; i++)
    // {
    // cout << dp[i] << " ";
    // }
    // cout << "\n";
    // ans = solve2(n);

    cout << "Case " << cnt << ": " << dp[n] << "\n";
    cnt++;
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}