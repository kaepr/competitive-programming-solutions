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
    long long n;
    cin >> n;

    vector<pair<int, long long>> val;
    for (long long i = 2; i * i <= n; ++i)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            ++cnt;
            n /= i;
        }
        if (cnt > 0)
        {
            val.push_back({cnt, i});
        }
    }
    if (n > 1)
    {
        val.push_back({1, n});
    }

    sort(val.rbegin(), val.rend());
    // for (auto x : val)
    // {
    //     trace(x.first);
    //     trace(x.second);
    // }
    vector<long long> ans(val[0].first, val[0].second);
    // for (auto x : ans)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (int i = 1; i < int(val.size()); ++i)
    {
        for (int j = 0; j < val[i].first; ++j)
        {
            ans.back() *= val[i].second;
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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