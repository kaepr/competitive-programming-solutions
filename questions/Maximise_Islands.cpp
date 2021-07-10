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

int n, m;
int grid[11][11];
int vis[11][11];
vector<int> szs;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (vis[x][y] == 1)
    {
        return false;
    }
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    if (grid[x][y] == 0)
    {
        return false;
    }
    if (grid[x][y] == 1)
    {
        return true;
    }
    return false;
    // return true;
}

void dfs(int x, int y, int &len)
{
    vis[x][y] = 1;
    len++;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i], len);
        }
    }
}

void islands()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                // not visited go on
                int len = 0;
                dfs(i, j, len);
                trace(len);
                szs.PB(len);
            }
        }
    }
}

void solve()
{
    szs.clear();
    memset(grid, 0, sizeof(grid));
    memset(vis, 0, sizeof(vis));
    // int n, m;
    cin >> n >> m;
    // int a[n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '.')
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = 1;
            }
        }
    }

    //0 is water, 1 is land

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    islands();

    for (auto x : szs)
    {
        cout << x << " ";
    }
    int val = 0;
    for (auto x : szs)
    {
        if (x <= 2)
        {
            val++;
        }
        else
        {
            val += (x / 2 + 1);
        }
    }
    trace(val);
    cout << "\n";
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