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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    p--;

    int cost[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int val1 = s[i] - 'a' + 1;
        int val2 = s[n - i - 1] - 'a' + 1;
        if (val2 < val1)
        {
            swap(val1, val2);
        }
        cost[i] = min(val2 - val1, 26 - val2 + val1);
    }

    // cout << "\n";
    int ans = 0;
    // trace(p);
    if (p >= n / 2)
    {
        p = n - p - 1;
    }
    // trace(p);

    // smallest index <= p such that cost[i] != 0

    vi v;
    int total = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (cost[i] != 0)
        {
            v.PB(i);
        }
        total += cost[i];
    }
    if (v.size() == 0)
    {
        cout << "0\n";
        return;
    }
    // trace(total);
    int l = v[0];
    int r = v[v.size() - 1];
    r = max(r, p);
    l = min(l, p);
    int cnt1 = total + (r - l) + (r - p);
    int cnt2 = total + (r - l) + (p - l);
    cout << min(cnt1, cnt2) << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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