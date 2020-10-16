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
    ll a[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 3);
    reverse(a, a + 3);
    bool found = false;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < 2; i++)
    {
        ll next = a[i + 1];
        // cout << "current element is " << a[i] << "\n";
        for (int j = a[i] - 1; j > next; j--)
        {
            // cout << "this happends\n";
            cout << j << "\n";
            found = true;
            return;
        }
    }
    if (!found)
    {
        cout << a[0] + 1 << "\n";
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