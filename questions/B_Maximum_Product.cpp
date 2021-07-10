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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    ll ans = -1 * 1e18;
    ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
    ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[0] * a[1]);
    ans = max(ans, a[n - 1] * a[3] * a[2] * a[0] * a[1]);
    cout << ans << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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