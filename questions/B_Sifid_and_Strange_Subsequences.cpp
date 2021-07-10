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
    ll n;
    cin >> n;
    vector<ll> v;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.PB(x);
    }

    sort(v.begin(), v.end());
    ll index = lower_bound(v.begin(), v.end(), 1) - v.begin();

    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // trace(index);
    if (index == n)
    {
        cout << n << "\n";
        return;
    }

    ll x = v[index];
    // x is the minimum positive element

    bool f = true;
    for (int i = 1; i < index; i++)
    {
        if (abs(v[i] - v[i - 1]) < x)
        {
            f = false;
            break;
        }
    }

    // trace(index, f, x);
    int ans = index + 1;
    if (!f)
    {
        ans--;
    }
    cout << ans << "\n";
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