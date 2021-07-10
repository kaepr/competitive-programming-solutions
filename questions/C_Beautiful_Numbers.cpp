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

const ll N = 1e6 + 10;
ll fact[N], invfact[N];
ll n, a, b;

bool check(ll val, ll a, ll b)
{
    while (val > 0)
    {
        if (val % 10 == a || val % 10 == b)
        {
            val /= 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
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

int main()
{
    init();
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << fact[i] << " ";
    // }
    // cout << "\n";
    cin >> a >> b >> n;
    // trace(a, b, n);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ll temp = i * a + (n - i) * b;
        ll k = 0;
        if (check(temp, a, b))
        {
            ans += getC(n, i);
            // trace(ans);
            ans %= MOD;
        }
    }
    ans %= MOD;
    cout << ans;

    return 0;
}