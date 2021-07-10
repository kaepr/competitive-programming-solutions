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

const int MAXN = 105;
int n, m;
int a[105][105];

bool isUnique(int i, int j)
{

    int upper = a[i - 1][j];
    int right = a[i][j + 1];
    int left = a[i][j - 1];
    int down = a[i + 1][j];

    if (i == 1)
    {
    }
    else if (i == n)
    {
    }

    if (a[i][j] != upper && a[i][j] != right && a[i][j] != left && a[i][j] != right)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            a[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (a[i][j] % 2 == 0)
                {
                    //do nothing
                }
                else
                {
                    a[i][j] = 1 + a[i][j];
                }
            }
            else
            {
                if (a[i][j] % 2 != 0)
                {
                    //do nothing
                }
                else
                {
                    a[i][j] = 1 + a[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
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