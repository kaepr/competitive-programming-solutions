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
    ll mid = n / 2;
    ll total = 0;
    for (ll i = 0; i < n; i++)
    {
        total += abs(a[i] - a[mid]);
    }
    cout << total << '\n';

    return 0;
}
