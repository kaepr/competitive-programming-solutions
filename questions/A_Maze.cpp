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
int n, m, k, need, s, cnt;
int vis[505][505];
char arr[505][505];

/*
        (x,y+1)
(x-1,y),(x,y) (x+1,y)
        (x,y-1)


*/

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y)
{
    if (x < n && y < m && x >= 0 && y >= 0 && arr[x][y] == '.' && vis[x][y] == 0)
    {
        return true;
    }
    return false;
}

void dfs(int x, int y)
{
    if (cnt >= need)
    {
        return;
    }

    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            cnt++;
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void solve()
{
    cin >> n >> m >> k;
    memset(vis, 0, sizeof(vis));
    memset(arr, 'a', sizeof(arr));
    int cnt = 0;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == '.')
            {
                s++;
                p.F = i;
                p.S = j;
            }
            // arr[i][j] = c;
        }
    }

    need = s - k;

    // trace(need, k, s);
    cnt = 1;
    dfs(p.F, p.S);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                cout << '#';
            }
            else
            {
                if (vis[i][j])
                {
                    cout << '.';
                }
                else
                {
                    cout << 'X';
                }
            }
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

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}