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
int num = 1;
int R = 1005, C = 1005;
int r, c;
int grid[1005][1005];

bool checkCommon(int x, int y)
{
    if (grid[x - 1][y] == 1 && grid[x][y + 1] == 1)
    {
        return true;
    }

    if (grid[x + 1][y] == 1 && grid[x][y + 1] == 1)
    {
        return true;
    }

    if (grid[x - 1][y] == 1 && grid[x][y - 1] == 1)
    {
        return true;
    }

    if (grid[x + 1][y] == 1 && grid[x][y - 1] == 1)
    {
        return true;
    }

    return false;
}

const int maxn = 305;
int arr[maxn][maxn];
int vis[maxn][maxn];
int r, c;

int dx = {-1, 0, 1, 0};
int dy = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y<1 y> c)
    {
        return false;
    }
    if (vis[x][y] == 1)
        return false;

    return true;
}

int sum = 0;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    
}

void solve()
{

    // int r, c;
    sum = 0;
    cin >> r >> c;
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;

    int maxxX, maxxY = 0;
    int maxx = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (grid[i][j] > maxx)
            {
                maxx = max(maxx, grid[i][j]);
                maxxX = i;
                maxxY = j;
            }
        }
    }

    cout << "Case #" << num << ": " << cnt << "\n";
    num++;
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