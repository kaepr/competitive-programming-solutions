#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.PB(x);
    }
    vector<ll> mult;
    // map<ll, ll> mp;
    vector<ll> rem;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % m == 0)
        {
            mult.PB(a[i]);
        }
        else
        {
            rem.PB(a[i]);
            // mp[a[i]]++;
        }
    }
    ll cnt = 0;
    if (mult.size() != 0)
    {
        cnt++;
    }

    // sort(rem.begin(), rem.end());
    for (ll i = 0; i < rem.size(); i++)
    {
        // ll elm = rem[i[]]
        rem[i] = rem[i] % m;
    }

    map<ll, ll> val;
    for (auto x : rem)
    {
        val[x]++;
    }

    // for (auto x : rem)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    for (auto x : rem)
    {
        // trace(x, cnt);
        if (val[x] != 0)
        {
            // cout << "here\n";
            ll elm = x;
            ll to_need = m - x;
            if (to_need == x && val[x] != 0)
            {
                cnt++;
                val[x] = 0;
            }
            else if (val[to_need] != 0 && to_need != elm)
            {
                ll cnt1 = val[elm];
                ll cnt2 = val[to_need];
                val[elm] -= min(cnt1, cnt2);
                val[to_need] -= min(cnt1, cnt2);
                cnt++;

                if (val[elm] > val[to_need])
                {
                    // cnt++;
                    val[elm]--;
                }

                if (val[elm] < val[to_need])
                {
                    // cnt++;
                    val[to_need]--;
                }

                if (val[elm] > val[to_need])
                {
                    cnt += val[elm];
                    // val[elm]--;
                }

                if (val[elm] < val[to_need])
                {
                    cnt += val[to_need];
                    // val[to_need]--;
                }

                val[elm] = 0;
                val[to_need] = 0;
            }
            else
            {

                cnt += val[x];
                val[x] = 0;
            }
        }
    }
    cout << cnt << "\n";
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