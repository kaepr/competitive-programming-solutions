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

int check(int a, int b)
{
    int div = max(a, b) / min(a, b);
    if (max(a, b) % min(a, b) != 0)
        div++;
    if (div <= 2)
    {
        return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.PB(x);
    }
    int cnt = 0;
    int elm = a[0];
    for (int i = 1; i < n; i++)
    {
        if (check(elm, a[i]))
        {
            // cout << "YES\n";
            // trace(elm, a[i]);

            elm = a[i];
        }
        else
        {
            if (elm >= a[i])
            {
                // cout << "HERE\n";
                // trace(elm, a[i]);
                while (!check(elm, a[i]))
                {
                    // trace(elm, a[i]);
                    if (elm % 2 == 0)
                    {
                        elm /= 2;
                    }
                    else
                    {
                        elm /= 2;
                        elm++;
                    }
                    // elm--;
                    cnt++;
                }
                // trace(elm, a[i]);
                elm = a[i];
            }
            else
            {
                while (!check(elm, a[i]))
                {
                    // cout << "here\n";
                    // trace(elm, a[i]);
                    elm *= 2;
                    // elm++;
                    // trace(elm, a[i]);
                    cnt++;
                }
                // trace(elm, a[i]);
                elm = a[i];
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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