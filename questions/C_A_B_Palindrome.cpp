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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.length();
    /*
    a = 0, b = 1
    */
    int ca = 0, cb = 0, cx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ca++;
        }
        else if (s[i] == '1')
        {
            cb++;
        }
        else
        {
            cx++;
        }
    }

    /*
    ca + cb + cx == a + b 
    */

    if (ca + cb + cx != a + b)
    {
        cout << -1 << "\n";
        return;
    }
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (s[n - i - 1] == '1')
            {
                f = true;
                break;
            }

            if (s[n - i - 1] == '?')
            {
                ca++;
                cx--;
                s[n - i - 1] = '0';
            }
        }
        else if (s[i] == '1')
        {
            if (s[n - i - 1] == '0')
            {
                f = true;
                break;
            }

            if (s[n - i - 1] == '?')
            {
                cb++;
                cx--;
                s[n - i - 1] = '1';
            }
        }
    }

    if (ca > a || cb > b)
    {
        cout << "-1\n";
        return;
    }

    if (f)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] == '?')
        {
            if (a - ca >= 2)
            {
                s[i] = '0';
                ca += 2;
                cx -= 2;
                s[n - i - 1] = '0';
            }
            else if (b - cb >= 2)
            {
                s[i] = '1';
                cb += 2;
                cx -= 2;
                s[n - i - 1] = '1';
            }
        }
    }

    if (a < 0 || b < 0)
    {
        cout << -1 << "\n";
        return;
    }

    int da = a - ca;
    int db = b - cb;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (da > 0)
            {
                s[i] = '0';
                da--;
            }
            else
            {
                s[i] = '1';
                db--;
            }
        }
    }
    // trace(s);
    // trace(a, b);
    // trace(ca, cb, cx);
    // trace(da, db);

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            cout << "-1\n";
            return;
        }
    }
    // trace(s);
    cout << s << "\n";
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