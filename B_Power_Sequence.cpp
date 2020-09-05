#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const long long inf = 1e15;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
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

    sort(a, a + n);

    ll c = 1;

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += abs(a[i] - c);
    }

    ll aMax = a[n - 1];

    ll ans1 = 0;

    ll sol = ans;

    // cout << "sol for only 1 is " << sol << "\n";
    c++;
    while (true)
    {
        for (ll i = 0; i < n; i++)
        {
            if (ans1 > ans + aMax)
            {
                break;
            }
            ans1 += abs(a[i] - binpow(c, i));
        }

        if (ans1 >= inf)
        {
            break;
        }

        if (ans1 > ans + aMax)
        {
            break;
        }
        else
        {
            sol = min(ans1, sol);
        }
        ans1 = 0;
        c++;
    }

    cout << sol << "\n";

    return 0;
}