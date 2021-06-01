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
const int N = 1e5 + 10;
int grid[3][N];
// int cnt[2][N];
int n, q;

bool isValid(int x, int y)
{
    // trace(x, y);
    if (x >= 1 && x <= 2 && y >= 1 && y <= n)
    {
        // cout << "valid\n";
        return 1;
    }
    return 0;
}

void solve()
{
    cin >> n >> q;
    vi top_row, bottom_row;
    bool possible = false;
    int blocked = 0;
    while (q > 0)
    {
        int x, y;
        cin >> x >> y;

        if (grid[x][y] == 0)
        {
            // grid was earlier ground
            grid[x][y] = 1 - grid[x][y];

            if (isValid(3 - x, y) && grid[3 - x][y])
            {
                blocked++;
            }

            if (isValid(3 - x, y - 1) && grid[3 - x][y - 1])
            {
                blocked++;
            }

            if (isValid(3 - x, y + 1) && grid[3 - x][y + 1])
            {
                blocked++;
            }
        }
        else
        {
            // grid was earlier lava
            grid[x][y] = 1 - grid[x][y];

            if (isValid(3 - x, y) && grid[3 - x][y])
            {
                blocked--;
            }

            if (isValid(3 - x, y - 1) && grid[3 - x][y - 1])
            {
                blocked--;
            }

            if (isValid(3 - x, y + 1) && grid[3 - x][y + 1])
            {
                blocked--;
            }
        }

        // trace(x, y, blocked);

        if (blocked > 0)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }

        q--;
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