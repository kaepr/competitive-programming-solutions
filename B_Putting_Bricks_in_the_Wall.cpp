#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }

    int one = 0;
    int zero = 0;

    vector<pair<int, int>> ans;
    int cnt = 0;

    if (a[1][2] == a[2][1] || a[n][n - 1] == a[n - 1][n])
    {
        if (a[1][2] == a[2][1])
        {
            if (a[n - 1][n] == a[1][2])
            {
                ans.pb(mp(n - 1, n));
            }
            if (a[n][n - 1] == a[1][2])
            {
                ans.pb(mp(n, n - 1));
            }
        }
        else if (a[n - 1][n] == a[n][n - 1])
        {
            if (a[n - 1][n] == a[1][2])
            {
                ans.pb(mp(1, 2));
            }
            if (a[n][n - 1] == a[2][1])
            {
                ans.pb(mp(2, 1));
            }
        }
    }
    else
    {
        if (a[1][2] == 1)
        {
            ans.pb(mp(1, 2));
        }

        if (a[2][1] == 1)
        {
            ans.pb(mp(2, 1));
        }

        if (a[n][n - 1] == 0)
        {
            ans.pb(mp(n, n - 1));
        }
        if (a[n - 1][n] == 0)
        {
            ans.pb(mp(n - 1, n));
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << "\n";
    }
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