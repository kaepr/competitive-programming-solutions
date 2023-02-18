
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

void solve()
{
}

int main()
{
    init();
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

const ll mod = 998244353;

void init2()
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
    }
}

ll ncr(ll n, ll r)
{
    if (n < 0 || r < 0 || n < r)
    {
        return 0;
    }
    ll ans = fact[n] * invfact[n - r] % mod * invfact[r] % mod;
    ans %= mod;
    return ans;
}

ll getC2(int n, int i)
{
    ll res = fact[n];
    ll div = fact[n - i] * fact[i];
    div %= mod;
    div = powmod(div, mod - 2, mod);
    return (res * div) % mod;
}


