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
    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    ll ans = 0;
    ll prevElm = -1;
    ll prevCnt = 0;
    ll b_ptr = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ll cnt = 0;
            for (ll j = b_ptr; j < m; j++)
            {
                if (b[j] == a[i])
                {
                    cnt++;
                }
                if (b[j] > a[i])
                {
                    break;
                }
                b_ptr++;
            }
            prevElm = a[i];
            ans += cnt;
            prevCnt = cnt;
        }
        else if (prevElm == a[i])
        {
            ans += prevCnt;
        }
        else
        {
            ll cnt = 0;
            for (ll j = b_ptr; j < m; j++)
            {
                if (b[j] == a[i])
                {
                    cnt++;
                }
                if (b[j] > a[i])
                {
                    break;
                }
                b_ptr++;
            }
            prevElm = a[i];
            ans += cnt;
            prevCnt = cnt;
        }

        // trace(ans, a[i]);
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