#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_sum(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ll x = a % 10;
        ans += x;
        a /= 10;
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    int ptr = 0;
    int a_points = 0;
    int b_points = 0;

    for (ll i = 0; i < n; i++)
    {
        if (pow_sum(a[i]) > pow_sum(b[i]))
        {
            a_points++;
        }
        else if (pow_sum(a[i]) < pow_sum(b[i]))
        {
            b_points++;
        }
        else if (pow_sum(a[i]) == pow_sum(b[i]))
        {
            a_points++;
            b_points++;
        }
    }

    if (a_points > b_points)
    {
        cout << 0 << " " << a_points << "\n";
    }
    else if (b_points > a_points)
    {
        cout << 1 << " " << b_points << "\n";
    }
    else if (a_points == b_points)
    {
        cout << 2 << " " << a_points << "\n";
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