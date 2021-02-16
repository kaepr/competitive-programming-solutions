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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> h;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.PB(x);
    }

    // for (auto x : h)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    if (k > 10000)
    {
        cout << -1 << "\n";
        return;
    }

    // ll suffix[n];
    // suffix[0] = h[0];
    // for (ll i = 1; i < n; i++)
    // {
    //     suffix[i] = suffix[i - 1] + h[i];
    // }

    // ll total = 0;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     if (h[i] > h[i + 1])
    //     {
    //         //continue
    //     }
    //     else
    //     {
    //     }
    // }

    ll currPlace = 1;
    int ptr = 0;
    // trace(n);
    bool flag = false;

    for (ll i = 0; i < n - 1; i++)
    {
        // trace(i);
        if (h[i] >= h[i + 1])
        {
            // trace(h[i], h[i + 1], i);
            continue;
        }
        else
        {
            // ll diff = h[i + 1] - h[i];
            k--;
            h[i]++;
            if (k <= 0)
            {
                flag = true;
                ptr = i;
                break;
                // cout << i + 1 << "\n";
                // return;
            }
            // h[i] += diff;
            i = -1;
            // if (diff >= k)
            // {
            //     h[i] += k;
            //     k = 0;
            //     if (k == 0)
            //     {
            //         cout << i + 1 << "\n";
            //         return;
            //     }
            // }
            // else
            // {
            //     k -= min(diff, k);
            //     h[i] += min(diff, k);
            //     i = -1;
            // }
        }
    }
    if (flag)
    {
        cout << ptr + 1 << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    // cout << "NEW\n";

    // for (ll i = 1; i <= k; i++)
    // {
    //     if (h[i] > h[i + 1])
    //     {
    //     }
    // }
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