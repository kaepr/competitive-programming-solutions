#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, s = 0, m = -2000000000;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        s = max(s + a[i], a[i]);
        m = max(m, s);
    }

    cout << m << "\n";

    return 0;
}