#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll sum = 0;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll b = 0;
    for (int i = 0; i < n; i++)
        b += a[i];

    if (b % 2 == 0)
    {
        cout << b << "\n";
        return 0;
    }

    ll smallest_odd = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            smallest_odd = min(a[i], smallest_odd);
        }
    }
    cout << b - smallest_odd << "\n";

    return 0;
}