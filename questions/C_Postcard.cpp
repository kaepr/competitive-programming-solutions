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

    /*
    
    * - snowflake
    ? - candy cone

    */
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();

    int snow = 0, candy = 0, cnt = 0;
    for (auto x : s)
    {
        if (x == '*')
        {
            snow++;
        }
        else if (x == '?')
        {
            candy++;
        }
        else
        {
            cnt++;
        }
    }

    if (cnt - snow - candy > k || (cnt < k && !snow))
    {
        cout << "Impossible\n";
        return;
    }

    string ans = "";
    int rm = max(k, cnt) - k, ad = k - min(k, cnt);
    // trace(rm, ad);
    if (!rm)
    {
        for (int i = 0; i < n; i++)
        {
            char c = 'a', c1 = s[i];
            if (i + 1 < n)
            {
                c = s[i + 1];
            }

            if (c == '*')
            {
                i++;
                if (ad)
                {
                    ans.append(ad, c1);
                    ad = 0;
                }
            }

            if (c == '?')
            {
                i++;
            }
            ans.append(1, c1);
        }
    }

    if (rm)
    {
        for (int i = 0; i < n; i++)
        {
            char c = 'a', c1 = s[i];
            if (i + 1 < n)
            {
                c = s[i + 1];
            }

            if (c == '?' || c == '*')
            {
                i++;
                if (rm)
                {
                    rm--;
                    continue;
                }
            }
            ans.append(1, c1);
        }
    }

    cout << ans;
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