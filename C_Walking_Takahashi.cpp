#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

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

void solve()
{
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    if (x > 0 && (x / d) >= k)
    {
        ll temp = x / d;
        x = x - (k)*d;
        cout << x << "\n";
        return 0;
    }

    ll y = x / d;
    x = x - y * d;
    k = k - y;

    if (k % 2 == 0)
        cout << abs(x) << "\n";
    else
        cout << min(abs(x - d), abs(x + d)) << "\n";

    return 0;
}