#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, n;
    cin >> a >> b >> n;

    if (a > n)
    {
        cout << 0 << "\n";
    }
    else
    {
        int ans = 0;
        while (a <= n && b <= n)
        {
            if (a > b)
            {
                b += a;
                ans++;
                //cout << "b is " << b << "\n";
            }
            else
            {
                a += b;
                ans++;
                //cout << "a is " << a << "\n";
            }
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}