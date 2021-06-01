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

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;

    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.PB(MP(x, y));
    }

    /*
    v[i].F = inital health
    v[i].S = deals b[i] damage
    */
    ll startIndex = -1;
    ll maxDiff = 1e18;

    for (ll i = 0; i < n; i++)
    {

        ll next = (i + 1) % n;
        ll currDiff = v[next].F - max((ll)0, v[next].F - v[i].S);

        if (currDiff < maxDiff)
        {
            startIndex = next;
            maxDiff = currDiff;
        }
    }

    // trace(startIndex);

    ll total = v[startIndex].F;
    for (ll i = startIndex + 1; i < n; i++)
    {
        if (i == 0)
        {
            total += max((ll)0, v[i].F - v[n - 1].S);
        }
        else
        {
            total += max((ll)0, v[i].F - v[i - 1].S);
        }
    }

    // trace(total);

    for (ll i = 0; i < startIndex; i++)
    {
        if (i == 0)
        {
            total += max((ll)0, v[i].F - v[n - 1].S);
        }
        else
        {
            total += max((ll)0, v[i].F - v[i - 1].S);
        }
    }
    cout << total << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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