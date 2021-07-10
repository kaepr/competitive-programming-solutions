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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != (i + 1))
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << 0 << "\n";
        return;
    }
    int cnt = 0;
    int start_index = 0, end_index = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == (i + 1))
        {
            start_index = i;
        }
        else
        {
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == (i + 1))
        {
            end_index = i;
        }
        else
        {
            break;
        }
    }

    // trace(start_index, end_index);

    for (int i = start_index + 1; i < end_index; i++)
    {
        if (a[i] == (i + 1))
        {
            // trace(i);
            cnt++;
        }
    }

    if (cnt)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 1 << "\n";
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