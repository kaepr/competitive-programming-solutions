#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 998244353;

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

ll fact[N];
void init()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

ll getC(int n, int i)
{
    ll res = fact[n];
    ll div = fact[n - i] * fact[i];
    div %= MOD;
    div = powmod(div, MOD - 2, MOD);
    return (res * div) % MOD;
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
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    ll sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
        sum1 %= MOD;
    }
    ll sum2 = 0;
    for (int i = n; i < 2 * n; i++)
    {
        sum2 += a[i];
        sum2 %= MOD;
    }
    ll diff = sum2 - sum1;
    diff %= MOD;
    ll cnt = getC(2 * n, n);
    cnt %= MOD;
    ll ans = diff * cnt;
    ans %= MOD;
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