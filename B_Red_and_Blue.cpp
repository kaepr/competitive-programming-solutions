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

int n, m;
int a[105], b[105];
// int ans = INT_MIN;
int dp[205];

int ans(int ptr1, int ptr2)
{
    if (dp[ptr1 + ptr2] != -1)
    {
        return dp[ptr1 + ptr2];
    }

    if (ptr1 > n)
    {
        if (ptr2 > m)
        {
            dp[ptr1 + ptr2] = 0;
            return 0;
        }
        else
        {
            dp[ptr1 + ptr2] = max(0, max(b[ptr2], b[ptr2] + ans(ptr1, ptr2 + 1)));
            return dp[ptr1 + ptr2];
        }
    }

    if (ptr2 > m)
    {
        if (ptr1 > n)
        {
            dp[ptr1 + ptr2] = 0;
            return 0;
        }
        else
        {
            dp[ptr1 + ptr2] = max(0, max(a[ptr1], a[ptr1] + ans(ptr1 + 1, ptr2)));
            return dp[ptr1 + ptr2];
        }
    }

    dp[ptr1 + ptr2] = max(0, max(a[ptr1] + ans(ptr1 + 1, ptr2), b[ptr2] + ans(ptr1, ptr2 + 1)));

    return dp[ptr1 + ptr2];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    // ans = INT_MIN;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    ans(0, 0);
    ans(0, 1);
    ans(1, 0);

    // dp[0] = 0;
    // dp[1] = max(a[1], b[1]);

    int sol = 0;
    for (int i = 0; i <= n + m; i++)
    {
        sol = max(sol, dp[i]);
    }

    cout << sol << "\n";
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