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
    //use cerr if u want to display at the bottom
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

const ll maxn = 1e6 + 10;
bool prime[maxn];
ll pre[maxn];

void calc()
{
    for (ll p = 2; p * p <= maxn; p++)
    {
        if (prime[p] == 0)
        {
            for (ll i = p * p; i <= maxn; i += p)
            {
                prime[i] = 1;
            }
        }
    }

    pre[0] = 0;
    pre[1] = 0;
    for (ll i = 2; i <= maxn; i++)
    {
        ll cnt;
        if (prime[i] == 0)
        {
            cnt = 1;
        }
        else
        {
            cnt = 0;
        }

        // else cnt = 0;

        pre[i] = pre[i - 1] + cnt;
        // trace(pre[i]);
    }
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    // trace(x, y);
    // // ll n = x;
    // trace(pre[x], y + 1);
    // for (int i = 0; i < 20; i++)
    // {
    //     trace(i, prime[i]);
    // }
    // cout << "\n";
    if (pre[x] < (y + 1))
    {
        cout << "Chef\n";
    }
    else
    {
        cout << "Divyam\n";
    }
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    calc();

    // for (ll i = 0; i < 10; i++)
    // {
    //     trace(i, prime[i]);
    // }
    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}