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
    int zeroFlag = 1;
    set<int> yes;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
        {
            zeroFlag = 0;
            yes.insert(a[i]);
        }
    }
    if (zeroFlag)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << yes.size() << "\n";
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