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

bool chk(int max_value, int poss_sum, int len)
{
    int maxx = 0, minn = 0;

    for (int i = 0; i < len; i++)
    {
        minn += i + 1;
        maxx += (max_value - i);
    }

    if (poss_sum > maxx || poss_sum < minn)
    {
        return false;
    }
    return true;
}

void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    int maxx = 0, minn = 0;

    int x = r - l + 1;

    /*
    x positions to fill
    all elements should be <= n, and distinct
    and their sum should be s
    */

    if (!chk(n, s, x))
    {
        cout << -1 << "\n";
        return;
    }

    // trace(n, x, minn, maxx);

    int ans[n + 1] = {0};
    map<int, int> val;

    bool f = false;
    int sum_rem = s;
    int rem_len = r - l + 1;
    int index = l;
    vi not_chosen;
    for (int i = n; i >= 1; i--)
    {
        if (sum_rem - i >= 0 && chk(i - 1, sum_rem - i, rem_len - 1))
        {
            // add i to ans array
            ans[index] = i;
            index++;
            val[i]++;
            sum_rem -= i;
            rem_len--;
        }
        else
        {
            not_chosen.PB(i);
        }
    }

    if (sum_rem != 0 || rem_len != 0)
    {
        cout << -1 << "\n";
        return;
    }

    int ptr = 0;

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = not_chosen[ptr];
            ptr++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\n";
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