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

int a[1001][1001];
int b[1001][1001];

void solve()
{
    int n, m, u, q;
    cin >> n >> m >> u >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        b[i][0] -= a[i - 1][0];
    }

    for (int i = 1; i < m; i++)
    {
        b[0][i] -= a[0][i - 1];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            b[i][j] = b[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }

    while (u > 0)
    {
        int k, r1, c1, r2, c2;
        cin >> k >> r1 >> c1 >> r2 >> c2;
        if (c2 + 1 < m)
        {
            b[r1][c2 + 1] -= k;
        }

        if (r2 + 1 < n)
        {
            b[r2 + 1][c1] -= k;
        }

        if (r2 + 1 < n && c2 + 1 < m)
            b[r2 + 1][c2 + 1] += k;

        b[r1][c1] += k;

        u--;
    }

    for (int i = 1; i < n; i++)

        b[i][0] += b[i - 1][0];

    for (int i = 1; i < m; i++)

        b[0][i] += b[0][i - 1];

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }

    //Making 2d prefix array for answering queries
    for (int i = 1; i < m; i++)

        b[0][i] += b[0][i - 1];

    for (int i = 1; i < n; i++)

        b[i][0] += b[i - 1][0];

    for (int i = 1; i < n; i++)

    {

        for (int j = 1; j < m; j++)

            b[i][j] += (b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]);
    }

    while (q > 0)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = b[r2][c2];

        if (r1 - 1 >= 0)

            ans -= b[r1 - 1][c2];

        if (c1 - 1 >= 0)

            ans -= b[r2][c1 - 1];

        if (r1 - 1 >= 0 && c1 - 1 >= 0)

            ans += b[r1 - 1][c1 - 1];

        cout << ans << "\n";
        q--;
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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