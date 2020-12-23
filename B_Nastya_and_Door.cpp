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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi dp(n);
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            dp[i] = 1;
        }
    }

    // for (auto x : dp)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int ans = 0;
    int currPeaks = 0;
    for (int i = 0; i <= k - 1; i++)
    {
        if (i == 0 || i == k - 1)
        {
            //continue
        }
        else if (dp[i] == 1)
        {
            currPeaks++;
        }
    }
    int currStart = 1;
    int currEnd = currStart + k - 1;
    int ansIndex = 0;
    int pre[n];
    pre[0] = dp[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + dp[i];
    }
    int index = 1;
    for (int i = 0; i < n - k + 1; i++)
    {
        int curr = pre[i + k - 2] - pre[i];
        // trace(i, curr);
        if (curr > ans)
        {
            if (curr > ans)
            {
                index = i + 1;
            }
            ans = curr;
            index = min(index, i + 1);
            // trace(index);
        }
        // trace(index);
    }
    cout << ans + 1 << " " << index << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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