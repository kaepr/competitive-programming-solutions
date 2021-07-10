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

void solve2()
{
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll pre[n];
    pre[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    // bool flag = true;
    double cc = (k * 1.0) / 100;
    ll added = 0;

    ll maxx = 0;
    for (ll i = 1; i < n; i++)
    {
        maxx = max(maxx, (100ll * a[i] - k * pre[i - 1] + k - 1) / k);
    }
    cout << maxx << "\n";

    // for (ll i = 1; i < n; i++)
    // {
    //     // trace(a[i], pre[i - 1]);
    //     double curr = (1.0) * (a[i] * 1.0 / (1.0 * pre[i - 1]));
    //     // trace(curr, cc);
    //     if (curr <= cc)
    //     {
    //         // continue;
    //         // cout << "GOOD\n";
    //     }
    //     else
    //     {
    //         //need to add something to get it less than cc
    //         //to get cc value, we must add atleast

    //         //adding to denominator
    //         double val = (1.0 * a[i] - cc * pre[i - 1] * 1.0) / (1.0 * cc);
    //         // // trace(val);
    //         ll val2 = (int)val;

    //         // // cout << "BAD\n";

    //         double curr2 = (1.0) * (a[i] * 1.0 / (pre[i - 1] * 1.0 + val2 * 1.0));
    //         // // trace(val2, curr2);
    //         while (curr2 > cc)
    //         {
    //             val2++;
    //             curr2 = (1.0) * (a[i] * 1.0 / (pre[i - 1] * 1.0 + val2 * 1.0));
    //             //     // trace(a[i], val2, curr2);
    //         }

    //         added += val2;
    //         for (ll i = 0; i < n; i++)
    //         {
    //             pre[i] += val2;
    //         }
    //     }
    // }

    // cout << added << "\n";
    // cout << "NEW\n";
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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