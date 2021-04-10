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
    int n, m;
    cin >> n >> m;
    vector<string> ppl;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ppl.PB(s);
    }
    map<pair<string, string>, int> mp;
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        mp[{a, b}] = 1;
        mp[{b, a}] = 1;
    }
    vector<string> ans;
    int val = pow(2, n);
    for (int i = 0; i < val; i++)
    {
        vector<string> cur;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                cur.PB(ppl[j]);
            }
        }
        bool f = true;
        for (int j = 0; j < cur.size(); j++)
        {
            for (int k = j + 1; k < cur.size(); k++)
            {
                if (mp[{cur[j], cur[k]}] == 1)
                {
                    f = false;
                    break;
                }
            }
            if (!f)
            {
                break;
            }
        }
        if (f && cur.size() > ans.size())
        {
            ans = cur;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << "\n";
    }
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