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

ll sums[1005];

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll bel = k + 1;
    ll totalSum = sums[k];
    ll ind = 0;

    if (n == k)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i <= n; i++)
    {
        ll curr = totalSum - sums[i] * 2;
        if (curr <= bel)
        {
            ind = i;
            break;
        }
    }
    trace(ind);
    for (int i = 1; i <= ind; i++)
    {
        cout << -i << " ";
    }
    for (int i = ind + 1; i <= k; i++)
    {
        cout << i << " ";
    }
    for (int i = k + 1; i <= n; i++)
    {
        cout << -i << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    sums[0] = 0;
    for (int i = 1; i < 1005; i++)
    {
        sums[i] = (i * (i + 1)) / 2;
    }

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}