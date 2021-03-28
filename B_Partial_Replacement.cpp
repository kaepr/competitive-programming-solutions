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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            v.PB(i);
        }
    }

    if (v.size() <= 2)
    {
        cout << v.size() << "\n";
    }
    else
    {
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << "\n";
        int tot1 = 1;
        int lastIndex = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - lastIndex <= k)
            {
                continue;
            }
            else
            {
                lastIndex = v[i - 1];
                tot1++;
            }
        }
        cout << tot1 + 1 << "\n";
        // trace(tot1 + 1);
    }
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