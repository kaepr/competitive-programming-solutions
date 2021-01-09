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

ll n;
ll a[300005];

ll calc()
{
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i + 1] && a[i] > a[i - 1])
        {
            ans++;
        }
        else if (a[i] < a[i + 1] && a[i] < a[i - 1])
        {
            ans++;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll total = calc();
    // trace(total);
    if (total == 0)
    {
        cout << 0 << "\n";
        return;
    }

    // max we can take down 3
    bool threePossible = false;
    int extra = 0;
    for (ll i = 1; i < n - 3; i++)
    {
        if (a[i] > a[i + 1] && a[i] > a[i - 1] && a[i + 1] < a[i + 2] && a[i + 2] > a[i + 3])
        {
            threePossible = true;
        }
    }

    for (ll i = 1; i < n - 3; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1] && a[i + 2] < a[i + 1] && a[i + 2] < a[i + 3])
        {
            threePossible = true;
        }
    }

    if (threePossible)
    {
        cout << total - 3 - extra << "\n";
        return;
    }

    bool twoPossible = false;
    for (ll i = 1; i < n - 2; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1] && a[i + 1] > a[i + 2])
        {
            twoPossible = true;
        }
    }

    for (ll i = 1; i < n - 2; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1] && a[i + 1] < a[i + 2])
        {
            twoPossible = true;
        }
    }

    if (twoPossible)
    {
        cout << total - 2 << "\n";
        return;
    }

    cout << total - 1 << "\n";

    // bool exist = false;
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