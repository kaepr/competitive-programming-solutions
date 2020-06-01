#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll temp = a[i] * (n - i);
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}