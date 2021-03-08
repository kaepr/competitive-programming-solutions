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

void solve()
{
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    // int uc = u, dc = d, rc = r, lc = l;

    bool flag = false;
    /*
    i<<1 = top right
    i<<2 = top left
    i<<3 = bottom right
    i<<4 = bottom left
    */
    for (int i = 0; i < 16; i++)
    {
        int uc = u, dc = d, rc = r, lc = l;
        // trace(uc, rc, dc, lc);
        // trace(i);
        if (i & 1)
        {
            uc--;
            rc--;
        }

        if (i & 2)
        {
            uc--;
            lc--;
        }

        if (i & 4)
        {
            dc--;
            rc--;
        }

        if (i & 8)
        {
            dc--;
            lc--;
        }

        if (dc >= 0 && uc >= 0 && rc >= 0 && lc >= 0 && uc <= n - 2 && dc <= n - 2 && rc <= n - 2 && lc <= n - 2)
        {
            flag = true;
        }
    }

    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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