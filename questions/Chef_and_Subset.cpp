#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n = 4;
    ll a[4];
    for (ll i = 0; i < 4; i++)
        cin >> a[i];

    ll k = 1 << 4;
    ll temp = 0;
    ll p = 0;
    for (ll i = 0; i < k; i++)
    {
        ll sum = 0;
        temp = 0;
        for (ll j = 0; j < n; j++)
        {
            ll b = 1 << j;
            if ((i & b) != 0)
            {
                sum += a[j];
                temp = 1;
            }
        }
        if (sum == 0 && temp == 1)
        {
            cout << "Yes\n";
            p = 1;
            break;
        }
    }
    if (!p)
    {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}