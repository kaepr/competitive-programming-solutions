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
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll pairs = 0;
    vector<bool> vis(n, false);
    for (ll i = 31; i >= 0; i--)
    {
        ll elm = 0;
        for (ll j = 0; j < n; j++)
        {
            if(a[j] < (1<<(i+1)) && a[j] >= (1<<i)){
                elm++;
            }
            
        }

        pairs += (elm) * (elm - 1) / 2;

    }
    cout << pairs << "\n";
}

int main()
{
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