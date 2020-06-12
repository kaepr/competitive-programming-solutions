#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll fact[1000001];

ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % mod;

        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}

void compute()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll k)
{
    if (k > n)
        return 0;

    ll res = fact[n];

    res = (res * power(fact[k], mod - 2)) % mod;
    res = (res * power(fact[n - k], mod - 2)) % mod;
    return res;
}

int main()
{
    compute();
    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = C(a, b);
        cout << ans << "\n";
    }
    return 0;
}