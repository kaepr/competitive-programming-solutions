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
ll INF = 1e17;
ll powmod(ll x, ll y)
{
    ll res = 1;
    // x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
        {
            if (res * x >= INF || res >= INF)
            {
                res = INF;
            }
            else
            {
                res = (res * x);
            }
        }

        y = y >> 1;
        if (x * x >= INF || x >= INF)
        {
            x = INF;
        }
        else
        {
            x = (x * x);
        }
    }
    return res;
}

const int MOD = 1e9 + 7;

ll calc(vector<ll> v)
{
    ll n = v.size();
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += abs(v[i] - 1);
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.PB(x);
    }

    sort(v.begin(), v.end());

    ll c = 1;
    ll f1 = calc(v);
    ll ans = f1;

    while (true)
    {

        ll curr = 0;
        for (ll i = 0; i < n; i++)
        {
            curr += abs(v[i] - powmod(c, i));
            if (curr >= INF)
            {
                break;
            }
        }

        if (!(powmod(c, n - 1) <= f1 + v[n - 1]) || curr >= INF)
        {
            break;
        }
        c++;
        ans = min(ans, curr);
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