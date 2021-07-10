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

ll a[200005];
ll b[200005];

void solve()
{
    ll n;
    cin >> n;
    // ll a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0, currMax = 0;
    // ll vis[n + 1];
    // for (ll i = 0; i <= n; i++)
    // {
    //     vis[i] = 0;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << vis[i] << " ";
    // }

    // ll b[n + 1];

    for (ll i = 1; i <= n; i++)
    {
        b[i] = a[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        ll index = a[i] + i;
        if (index <= n)
        {
            b[index] = max(b[i] + a[index], b[index]);
        }
    }

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << "\n";

    // ll maxElementYet = 0;
    // for (ll i = 1; i <= n; i++)
    // {
    //     ll curr = a[i];

    //     ll toAdd = a[i];
    //     // trace(a[i]);
    //     if (vis[i] == 0)
    //     {
    //         // cout << "Here\n";
    //         for (ll j = i + toAdd; j <= n; j = j + toAdd)
    //         {
    //             curr += a[j];
    //             // trace(curr);
    //             toAdd = a[j];
    //             vis[j] = 1;
    //         }
    //     }
    //     maxElementYet = max(curr, maxElementYet);
    //     currMax = max(currMax, curr);
    //     vis[i] = 1;

    //     // trace(i, curr);
    // }
    // cout << currMax << "\n";
    cout << *max_element(b, b + n + 1) << "\n";
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