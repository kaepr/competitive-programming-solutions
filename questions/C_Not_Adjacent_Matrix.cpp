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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }

    int cnt = 0;

    int a[n][n] = {0};
    int odd = 1, even = 2;
    int end = n * n;
    // if (end % 2 == 0)
    // {
    //     even = end;
    // }
    // else
    // {
    //     even = end - 1;
    // }
    bool evenFlag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (odd > n * n)
            {
                evenFlag = true;
            }
            if (evenFlag)
            {
                cout << even << " ";
                even += 2;
            }
            else
            {
                cout << odd << " ";
                odd += 2;
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

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}