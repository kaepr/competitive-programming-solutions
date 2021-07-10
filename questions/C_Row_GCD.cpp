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
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[n + 1], b[m + 1];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    for (ll i = 1; i <= m; i++)
        cin >> b[i];

    a[0] = 0;
    b[0] = 0;
    // ll currGCD = findGCD(a, n);
    ll G;
    if (n == 1)
    {
        G = 0;
    }
    else
    {
        G = a[2] - a[1];
    }

    // trace(G);
    for (ll i = 3; i <= n; i++)
    {

        G = gcd(G, a[i] - a[1]);
        // trace(G);
    }

    // cout << gcd(a[1] + b[1], 0) << " ";

    // ll G = 0;
    // trace(G);
    for (ll i = 1; i <= m; i++)
    {
        // trace(a[1] + b[i]);
        cout << abs(gcd(a[1] + b[i], G)) << " ";
    }
    cout << "\n";

    // for (ll i = 0; i < m; i++)
    // {
    //     ll num = b[i];
    //     // trace(num);
    //     ll ans = a[0] + num;
    //     ll last = a[0] + num;
    //     for (ll j = 1; j < n; j++)
    //     {
    //         // cout << a[j] + num << " ";
    //         ans = gcd(ans, a[j] + num);
    //         last = a[j] + num;
    //     }
    //     // cout << "\n";
    //     cout << ans << " ";
    // }
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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