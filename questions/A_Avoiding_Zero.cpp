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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    if (sum == 0)
    {
        cout << "NO\n";
    }
    else if (sum > 0)
    {
        cout << "YES\n";
        sort(a, a + n);
        reverse(a, a + n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
    else
    {
        cout << "YES\n";
        sort(a, a + n);
        // reverse(a,a+n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
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