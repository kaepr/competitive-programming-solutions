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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int pre[n], suf[n];
    pre[0] = a[0], suf[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        pre[i] = a[i] ^ pre[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] ^ a[i];
    }

    if (pre[n - 1] == 0)
    {
        cout << "YES\n";
        return;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << pre[i] << " ";
    // }

    // cout << "\n";

    // for (int i = 0; i < n; i++)
    // {
    //     cout << suf[i] << " ";
    // }
    // cout << "\n";

    /*
    need to find such atleast 3 subarrays whose xor is equal
    
    abcd efgh hijk
       i j ---
    */

    int xorr = a[0];

    for (int i = 1; i < n; i++)
    {
        int mid_xor = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (mid_xor == xorr && mid_xor == pre[n - 1])
            {
                cout << "YES\n";
                return;
            }
            mid_xor ^= a[j];
        }
        xorr ^= a[i];
    }
    cout << "NO\n";
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