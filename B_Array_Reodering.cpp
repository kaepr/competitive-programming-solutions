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
    vi v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.PB(x);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    vi tmp_even, tmp_odd;
    for (auto x : v)
    {
        if (x % 2 == 0)
        {
            tmp_even.PB(x);
        }
        else
        {
            tmp_odd.PB(x);
        }
    }

    vi last;
    for (auto x : tmp_even)
    {
        last.PB(x);
    }

    for (auto x : tmp_odd)
    {
        last.PB(x);
    }

    map<int, int> mp;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (last[i] % 2 == 0)
        {
            ans += (n - i - 1);
        }
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(last[i], 2 * last[j]) > 1)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
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