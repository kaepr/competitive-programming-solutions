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
    vector<ll> a;
    vector<ll> odd;
    vector<ll> even;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.PB(x);
        if (x % 2 == 0)
        {
            even.PB(x);
        }
        else
        {
            odd.PB(x);
        }
    }

    for (int i = 0; i < odd.size(); i++)
    {
        if (i == odd.size() - 1)
        {
            cout << odd[i] << " ";
        }
        else
        {
            cout << odd[i] << " ";
        }
    }

    for (int i = 0; i < even.size(); i++)
    {

        cout << even[i] << " ";
    }
    cout << "\n";
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