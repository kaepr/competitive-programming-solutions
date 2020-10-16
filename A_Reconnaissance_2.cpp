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

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int diff = INT_MAX;
    int ind1 = 0, ind2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int change = abs(a[i] - a[i + 1]);
        if (change < diff)
        {
            diff = change;
            ind1 = i + 1;
            ind2 = i + 2;
        }
    }
    int change = abs(a[n - 1] - a[0]);

    if (change < diff)
    {
        diff = change;
        ind1 = n;
        ind2 = 1;
    }

    cout << ind1 << " " << ind2 << "\n";

    return 0;
}