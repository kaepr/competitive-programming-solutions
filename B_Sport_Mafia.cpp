#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    ll l = 0, r = n;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (((n - m) * (n - m + 1) / 2) - m == k)
        {
            cout << m;
            return 0;
        }
        else if (((n - m) * (n - m + 1) / 2) - m < k)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return 0;
}