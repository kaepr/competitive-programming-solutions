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

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    ll mx = a[0];

    for (ll i = 1; i < n; i++)
    {
        if (a[i] >= mx)
        {
            // ans += mx - a[i];
            mx = a[i];
        }
        else if (a[i] < mx)
        {
            ans += mx - a[i];
        }
    }

    cout << ans << "\n";

    return 0;
}