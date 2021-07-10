#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

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

const int MOD = 1e9 + 7;

/*

bread sausage cheese

*/

void solve()
{
    string s;
    cin >> s;
    vector<ll> items, prices;
    for (ll i = 0; i < 3; i++)
    {
        ll x;
        cin >> x;
        items.PB(x);
    }

    for (ll i = 0; i < 3; i++)
    {
        ll x;
        cin >> x;
        prices.PB(x);
    }

    ll r;
    cin >> r;

    ll bneed = 0, sneed = 0, cneed = 0;
    for (auto x : s)
    {
        if (x == 'B')
        {
            bneed++;
        }
        else if (x == 'S')
        {
            sneed++;
        }
        else if (x == 'C')
        {
            cneed++;
        }
    }

    ll ans = 0;

    ll one_price = prices[0] * bneed + prices[1] * sneed + prices[2] * cneed;

    // bread sausage cheese

    while (true)
    {
        if (r <= 0)
        {
            break;
        }

        ll curr_b_have = min(bneed, items[0]);

        ll curr_s_have = min(sneed, items[1]);

        ll curr_c_have = min(cneed, items[2]);

        items[0] -= curr_b_have;
        items[1] -= curr_s_have;
        items[2] -= curr_c_have;

        ll b_extra_needed = bneed - curr_b_have;
        ll s_extra_needed = sneed - curr_s_have;
        ll c_extra_needed = cneed - curr_c_have;

        if (b_extra_needed == bneed && s_extra_needed == sneed && c_extra_needed == cneed)
        {
            // trace(ans);
            // trace(r, one_price);
            ans += r / one_price;
            // trace(ans);
            break;
        }

        if (b_extra_needed <= bneed)
        {
            r -= b_extra_needed * prices[0];
        }

        if (s_extra_needed <= sneed)
        {
            r -= s_extra_needed * prices[1];
        }

        if (c_extra_needed <= cneed)
        {
            r -= c_extra_needed * prices[2];
        }
        // trace(ans, r);
        // trace(items[0]);
        // trace(items[1]);
        // trace(items[2]);

        if (r >= 0)
        {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}