#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
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

ull sumDigits(ull n)
{
    ull ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}



void solve()
{
    ull n, s;
    cin >> n >> s;
    if (sumDigits(n) <= s)
    {
        cout << "0\n";
    }
    else
    {
        ull ans = 0;
        ull mult = 1;
        ull mult2 = 1;
        while (true)
        {
            ull last = (n / mult) % 10;
            ull add = (10 - last) * mult;
            ans += add;
            n += add;
            if (sumDigits(n) <= s)
            {
                cout << ans << "\n";
                return;
            }
            mult *= 10;
            // mult2 *= 10;
        }
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