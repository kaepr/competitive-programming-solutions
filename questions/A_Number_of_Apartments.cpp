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
    for (int i = 0; i <= n / 3; i++)
    {
        for (int j = 0; j <= n / 5; j++)
        {
            for (int k = 0; k <= n / 7; k++)
            {
                if (n - i * 3 - j * 5 - k * 7 == 0)
                {
                    cout << i << " " << j << " " << k << "\n";
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
    return;
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