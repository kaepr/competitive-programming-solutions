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
    ll n, T;
    cin >> n >> T;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int p[n];
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        if ( 2 * a[i] < T)
        {
            p[i] = 1;
        }
        else if (2 * a[i] > T)
        {
            p[i] = 0;
        }
    }

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1)
        {
            if (flag)
            {
                flag = !flag;
                p[i] = 1;
            }
            else
            {
                p[i] = 0;
                flag = !flag;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";

    cout << "\n";
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