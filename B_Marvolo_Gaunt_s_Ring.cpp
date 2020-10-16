#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll p, q, r, n;
    cin >> n >> p >> q >> r;

    ll a[n];

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    sort(a, a + n);

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";

    // cout << "\n";

    if (p >= 0)
    {
        if (a[n - 1] >= 0)
        {
            ans += p * a[n - 1];
        }
        else
        {
            ans += max(p * a[0], p * a[n - 1]);
        }
    }
    else
    {
        // cout << p * a[0] << "\n";
        // cout << p * a[n - 1] << "\n";
        ans += max(p * a[0], p * a[n - 1]);
    }

    // cout << "Ans right now is " << ans << "\n";

    if (q >= 0)
    {
        if (a[n - 1] >= 0)
        {
            ans += q * a[n - 1];
        }else
        {
            ans += max(q * a[0], q * a[n - 1]);
        }
    }
    else
    {
        ans += max(q * a[0], q * a[n - 1]);
    }

    // cout << "Ans right now is " << ans << "\n";

    if (r >= 0)
    {
        if (a[n - 1] >= 0)
        {
            ans += r * a[n - 1];
        }else
        {
            ans += max(r * a[0], r * a[n - 1]);
        }
    }
    else
    {
        ans += max(r * a[0], r * a[n - 1]);
    }

    // cout << "Ans right now is " << ans << "\n";

    cout << ans << "\n";

    return 0;
}