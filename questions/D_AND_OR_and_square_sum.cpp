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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int bit_cnt[22] = {0};

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (a[i])
        {
            if (a[i] & 1)
                bit_cnt[j]++;
            j++;
            a[i] >>= 1;
        }
    }

    ll ans = 0, num = 0;
    for (int j = 0; j < n; j++)
    {
        num = 0;
        ll x = 1;
        for (int i = 0; i < 22; i++)
        {
            if (bit_cnt[i])
            {
                num += x;
                bit_cnt[i]--;
            }
            x *= 2;
        }
        ans += num * num;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t = 1;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}