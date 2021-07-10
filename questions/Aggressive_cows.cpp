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

ll n, c;
ll pos[100005];

bool check(int x)
{
    //cow placed at pos[0]
    int cowsPlaced = 1;
    int lastPos = pos[0];
    for (int i = 1; i < n; i++)
    {
        int dist = pos[i] - lastPos;
        if (dist >= x)
        {
            cowsPlaced++;
            lastPos = pos[i];
            if (cowsPlaced >= c)
            {
                return true;
            }
        }
    }
    if (cowsPlaced >= c)
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
    cin >> n >> c;
    ll l = 0, r = 1e9 + 5;

    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    sort(pos, pos + n);
    ll ans = INT_MIN;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (check(m))
        {
            l = m + 1;
            ans = max(ans, m);
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans << "\n";
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