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
int n, sum;
const int maxn = 1e6 + 5;
int dp[maxn];
int coins[105];
// int dp[maxn];

// dp[i] stores minimum numbers of coins required to form this sum

int calc(int rem_sum, int ptr)
{
    if (rem_sum < 0 || ptr < 0)
    {
        return 1e9;
    }

    if (rem_sum == 0)
    {
        return 0;
    }

    if (dp[rem_sum] != -1)
    {
        return dp[rem_sum];
    }

    int ans = 1e9;
    if (rem_sum >= coins[ptr])
    {
        // chose this coin again
        ans = min(ans, 1 + calc(rem_sum - coins[ptr], ptr));

        // choose this coin and move forward
        ans = min(ans, 1 + calc(rem_sum - coins[ptr], ptr - 1));

        // do not choose this coin
        // ans = min(ans, calc(rem_sum, ptr - 1));
    }
    else
    {
        ans = calc(rem_sum, ptr - 1);
    }

    dp[rem_sum] = ans;

    return ans;
}

void solve()
{
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = calc(sum, n - 1);
    if (ans >= 1e9 || ans == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
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