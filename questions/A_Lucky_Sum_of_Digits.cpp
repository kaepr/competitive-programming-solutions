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
    ll n;
    cin >> n;
    bool f = false;
    ll cnt4 = 0, cnt7 = 0;
    for (int i = 0; i <= n; i++)
    {
        ll change = n - 4 * i;
        // cout << change % 7 << "\n";
        if (change >= 0 && change % 7 == 0)
        {
            // cout << "YES\n";
            cnt4 = i;
            cnt7 = change / 7;
            f = true;
            // trace(change, cnt4, cnt7);
            break;
        }
    }

    // trace(cnt4, cnt7);

    if (f)
    {
        for (int i = 0; i < cnt4; i++)
        {
            cout << 4;
        }
        for (int i = 0; i < cnt7; i++)
        {
            cout << 7;
        }
    }
    else
    {
        cout << -1 << "\n";
    }
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