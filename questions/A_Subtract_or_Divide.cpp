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
void __f(const char *names, Arg1 &&arg1, Args &&... args)
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
    vector<ll> v;

    // Note that this loop runs till square root
    // for (ll i = 1; i <= sqrt(n); i++)
    // {
    //     if (n % i == 0)
    //     {
    //         // If divisors are equal, print only one
    //         if (n / i == i)
    //         {
    //             v.PB(i);
    //         }
    //         else
    //         {
    //             v.PB(i);
    //             v.PB(n / i);
    //         }
    //     }
    // }
    // sort(v.begin(), v.end());
    // // for (auto x : v)
    // // {
    // //     cout << x << " ";
    // // }
    // // cout << "\n";
    if (n == 1)
    {
        cout << 0 << "\n";
    }
    else if (n == 2)
    {
        cout << 1 << "\n";
    }
    else if (n == 3)
    {
        cout << 2 << "\n";
    }
    else if (n % 2 == 0)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 3 << "\n";
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