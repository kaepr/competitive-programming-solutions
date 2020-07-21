#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

bool isPointOnLine(int y, int x, int a)
{
    if (y == a - x)
    {
        return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q > 0)
    {
        int xi, yi;
        cin >> xi >> yi;

        int f = 1;
        ll l = 1, r = n;
        int ans = n+1;
        while (l <= r)
        {
            ll m = l + (r - l)/2;
            if(xi+yi <= a[m]){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        if (xi + yi == a[ans])
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans -1 << "\n";
        }
        q--;
    }
}

int main()
{
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