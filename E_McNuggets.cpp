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
    ll n, k;
    cin >> n >> k;
    //k is the number of nuggets at the end
    ll total = 0;
    ll prev = 1;
    ll action_counter = 1;
    ll ate = 0;
    // while (action_counter <= n)
    // {
    //     if (action_counter == 1)
    //     {
    //         total += 1;
    //         prev++;
    //     }
    // }
    // ll curr = n, cnt = k;
    // while (true)
    // {
    //     ll sum = (curr) * (curr + 1) / 2;
    //     ll sum1 = (curr)
    // }

    ll l = 0, r = 1e9 + 10;
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        ll totalSum = (m) * (m + 1) / 2 - (n - m);
        if (totalSum == k)
        {
            cout << n - m << "\n";
            return;
        }
        else if (totalSum > k)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    // cout << ate << "\n";
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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