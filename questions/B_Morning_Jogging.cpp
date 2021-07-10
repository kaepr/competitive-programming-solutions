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

void solve()
{
    ll n, m;
    cin >> n >> m;

    /*
    
    n + 1 positions

    m paths between every position

    m runners

    b[i][j],  => from i-1 to i, the length is b[i][j]

    */

    ll b[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    ll ans[n][m];
    /*
    ans[i][j], 
    i denotes which position
    j th denotes which runner

    a[i][j] = value taken

    */

    bool f = true;
    int cnt = 0;
    int rev = 1;
    for (ll i = 0; i < n; i++)
    {
        sort(b[i], b[i] + m);
        reverse(b[i], b[i] + m);
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    for (int c = 0; c < m; c++)
    {
        int mn = MOD;
        int mini = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i][m - 1] < mn)
            {
                mn = b[i][m - 1];
                mini = i;
            }
        }
        trace(mn, mini, c);
        swap(b[mini][c], b[mini][m - 1]);
        sort(b[mini] + c + 1, b[mini] + m);
        reverse(b[mini] + c + 1, b[mini] + m);
    }

    cout << "ans\n";
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
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