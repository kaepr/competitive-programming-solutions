#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if (n >= (a - x) + (b - y))
    {
        cout << x * y << "\n";
    }
    else
    {
        ll ansA = 0;
        ll ansB = 0;

        ll aDifference = min(a - x, n);
        ll newNValue = n - aDifference;
        ll newAValue = a - aDifference;
        ll bDifference = min(b - y, newNValue);
        ll newBvalue = b - bDifference;
        ansA = newAValue * newBvalue;

        bDifference = min(b - y, n);
        newNValue = n - bDifference;
        newBvalue = b - bDifference;
        aDifference = min(a - x, newNValue);
        newAValue = a - aDifference;
        ansB = newAValue * newBvalue;

        cout << min(ansA, ansB) << "\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}