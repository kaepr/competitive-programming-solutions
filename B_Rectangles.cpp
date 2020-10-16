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
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k1 = 0, k0 = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                k1++;
            else
                k0++;
        }
        // cout << pow(2, k1) << "\n";
        // cout << pow(2, k0) << "\n";

        ans += pow(2, k1) + pow(2, k0) - 2;
    }

    // cout << "ans currently is " << ans << "\n";

    for (int i = 0; i < m; i++)
    {
        int k1 = 0, k0 = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] == 1)
                k1++;
            else
                k0++;
        }
        ans += pow(2, k1) + pow(2, k0) - 2;
    }

    cout << ans - m * n << "\n";

    return 0;
}