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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int curr = n;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i >= curr)
        {
            if (i - a[i] < curr)
            {
                curr = i - a[i];
            }
            continue;
        }
        cnt++;
        curr = i - a[i];
    }
    cout << cnt << "\n";

    return 0;
}