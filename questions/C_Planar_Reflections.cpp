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

ll powmod(ll x, ll y, ll mod)
{
    ll res = 1;
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

int dp[1001][1001][2];
int N, K;

int calc(int n, int k, int dir)
{
    if (k == 1)
        return 1;

    if (dp[n][k][dir] != -1)
        return dp[n][k][dir];

    int ans = 2;

    if (dir)
    {
        //goes right
        if (n < N)
        {
            ans += calc(n + 1, k, dir) - 1;
            ans %= MOD;
        }

        if (n > 1)
        {
            ans += calc(n - 1, k - 1, 1 - dir) - 1;
            ans %= MOD;
        }

        dp[n][k][dir] = ans;
    }
    else
    {
        //goes left
        if (n > 1)
        {
            ans += calc(n - 1, k, dir) - 1;
            ans %= MOD;
        }

        if (n < N)
        {
            ans += calc(n + 1, k - 1, 1 - dir) - 1;
            ans %= MOD;
        }

        ans %= MOD;
        dp[n][k][dir] = ans;
    }
    return dp[n][k][dir];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    // ll n, k;
    cin >> N >> K;
    cout << calc(1, K, 1) << "\n";
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