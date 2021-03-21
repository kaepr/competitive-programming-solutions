#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const ll MOD = 998244353;

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

ll powmod(ll x, ll y, ll mod)
{
    // trace(x, y, MOD);
    ll res = 1;
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

const ll mod = 998244353;
ll n;

const ll N = 300005;

ll fact[N], invfact[N];
void init()
{
    fact[0] = 1;
    ll i;
    for (i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    i--;
    invfact[i] = powmod(fact[i], mod - 2, mod);
    for (i--; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        // invfact[i] %= MOD;
    }
}

ll ncr(ll n, ll r)
{
    // trace(n, r);
    if (n < 0 || r < 0 || n < r)
    {
        return 0;
    }
    ll ans = fact[n] * invfact[n - r] % mod * invfact[r] % mod;
    ans %= mod;
    return ans;
}

ll getC(int n, int i)
{
    ll res = fact[n];
    ll div = fact[n - i] * fact[i];
    div %= mod;
    div = powmod(div, mod - 2, mod);
    return (res * div) % mod;
}

void solve()
{
    init();
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << fact[i] << " ";
    // }
    // cout << "\n";
    cin >> n;
    // trace(n);
    vector<ll> a;
    for (ll i = 0; i < 2 * n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    // for (ll i = 0; i < 2 * n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    ll sum1 = 0;
    for (ll i = 0; i < n; i++)
    {
        sum1 = (sum1 + a[2 * n - i - 1] - a[i]) % mod;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     sum1 += a[i];
    //     sum1 %= mod;
    // }
    // ll sum2 = 0;
    // for (int i = n; i < 2 * n; i++)
    // {
    //     sum2 += a[i];
    //     sum2 %= mod;
    // }
    // ll diff = abs(sum2 - sum1);
    // diff %= mod;
    ll cnt = ncr(2 * n, n);
    // cnt %= mod;
    ll ans = sum1 * cnt;
    ans %= mod;
    cout << ans;
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