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
    string s1, s2;
    cin >> s1 >> s2;
    vector<pair<int, int>> index;
    // vi index;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            index.PB(MP(i + 1, 1));
        }
    }
    // for (auto x : index)
    // {
    //     cout << x.first << " ";
    // }
    // cout << "\n";

    if (index.size() == 0)
    {
        cout << "0\n";
        return;
    }

    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < index.size(); i++)
    {
        int elm = index[i].first;

        if (index[i].second == 1)
        {
            ans++;
            index[i].second = 0;
            // trace(elm);
            for (int j = i + 1; j < index.size(); j++)
            {
                int currElm = index[j].first;
                // trace(currElm);
                if (currElm - elm == 2)
                {
                    index[j].second = 0;
                    elm = currElm;
                }
            }
        }
    }

    cout << ans << "\n";
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