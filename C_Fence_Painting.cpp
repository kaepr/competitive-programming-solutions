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

const int maxn = 1e5 + 5;
int n, m;
int a[maxn], b[maxn], c[maxn], ans[maxn];
vector<int> g[maxn];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] != a[i])
            g[b[i]].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    int last = -1;

    if ((int)g[c[m - 1]].size() > 0)
    {
        last = g[c[m - 1]].back();
        g[c[m - 1]].pop_back();
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == c[m - 1])
            {
                last = i;
                break;
            }
        }
    }

    if (last == -1)
    {
        cout << "NO\n";
        return;
    }

    ans[m - 1] = last;
    for (int i = 0; i < m - 1; i++)
    {
        if ((int)g[c[i]].size() == 0)
        {
            ans[i] = last;
        }
        else
        {
            ans[i] = g[c[i]].back();
            g[c[i]].pop_back();
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() > 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
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