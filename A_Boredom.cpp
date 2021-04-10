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
const ll maxn = 1e5 + 5;
ll freq[maxn + 1], a[maxn + 1], dp[maxn + 1];
ll n;

void solve()
{

    // ll n;
    cin >> n;
    // ll a[n],freq[n+1]
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = freq[1];
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " " << freq[i] << "\n";
    // }
    // cout << dp[0] << " " << dp[1] << " ";
    for (ll i = 2; i <= maxn; i++)
    {
        // either chose previous (i-1), or choose previous to previous, and add current sum
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
        // cout << dp[i] << " ";
    }
    // cout << "\n";

    cout << dp[maxn] << "\n";
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