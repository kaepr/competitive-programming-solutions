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
const ll MAXN = 2e5 + 10;
string s;
ll n;

ll dp[MAXN][2];

ll calc(ll ptr, ll prev)
{
    if (ptr < 0)
    {
        return 0;
    }

    if (dp[ptr][prev] != -1)
    {
        return dp[ptr][prev];
    }

    ll ans;

    if (s[ptr] == '?')
    {
        
    }
    else if (s[ptr] == '1')
    {
    }
    else if (s[ptr] == '0')
    {
    }

    dp[ptr][prev] = ans;
    return ans;
}

void solve()
{
    cin >> s;
    n = s.length();

    memset(dp, -1, sizeof(dp));
    if (s[0] == '1')
    {
        dp[0][1] = 1;
        dp[0][0] = 1;
        calc(1, 1);
    }
    else if (s[0] == '0')
    {
        dp[0][1] = 0;
        dp[0][0] = 1;
        calc(1, 0);
    }
    else
    {
        dp[0][1] = 1;
        dp[0][0] = 1;
        ll ans = calc(1, 1);
        ans = max(ans, calc(1, 0));
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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