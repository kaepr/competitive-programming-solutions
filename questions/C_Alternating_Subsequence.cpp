#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll pPtr = 0;
    ll nPtr = 0;

    if (a[0] > 0)
        pPtr = 1;
    else
        nPtr = 1;

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll cur = a[i];
        ll j = i+1;
        if(j<n && a[i]*a[j] < 0)
            sum += a[i];
        
        if(j < n && a[j]*a[i] > 0)
            a[j] = max(a[j], a[i]);
        
        if(i==n-1)
            sum += a[n-1];
    }
    cout << sum << "\n";
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