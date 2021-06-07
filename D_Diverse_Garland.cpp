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

string fix(string s)
{
    int n = s.length();
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            char c = s[i + 1];
            char next = s[i + 2];
            if (c == next)
            {
                // XXX
                if (c == 'R')
                {
                    c = 'G';
                }
                else if (c == 'G')
                {
                    c = 'B';
                }
                else if (c == 'B')
                {
                    c = 'R';
                }
                s[i + 1] = c;
            }
            else
            {
                // XXY
                // _.c.next
                if (next == 'R')
                {
                    if (c == 'G')
                    {
                        c = 'B';
                    }
                    else
                    {
                        c = 'G';
                    }
                }
                else if (next == 'G')
                {
                    if (c == 'R')
                    {
                        c = 'B';
                    }
                    else
                    {
                        c = 'R';
                    }
                }
                else if (next == 'B')
                {
                    if (c == 'G')
                    {
                        c = 'R';
                    }
                    else
                    {
                        c = 'G';
                    }
                }
                s[i + 1] = c;
            }
        }
    }
    return s;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << 0 << "\n";
        cout << s << "\n";
        return;
    }
    if (n == 2)
    {
        if (s[0] == s[1])
        {
            if (s[0] == 'R')
            {
                s[0] = 'G';
            }
            else if (s[0] == 'G')
            {
                s[0] = 'B';
            }
            else if (s[0] == 'B')
            {
                s[0] = 'R';
            }
        }
        cout << 1 << "\n";
        cout << s << "\n";
        return;
    }

    string s_orig = s;
    string s_new = fix(s);
    // trace(s_new);
    reverse(s_new.begin(), s_new.end());
    string s_new2 = fix(s_new);
    // trace(s_new2);
    reverse(s_new2.begin(), s_new2.end());
    // trace(s_new);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s_orig[i] != s_new2[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    cout << s_new2 << "\n";
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