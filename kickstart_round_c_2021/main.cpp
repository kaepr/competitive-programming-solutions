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

int caseNo = 1;

void solve()
{
    int ans = 0;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int options[n] = {0};

    for (int i = 0; i < n; i++)
    {
        int val = s[i] - 'a' + 1;
        options[i] = min(val, k);
    }

    for (int i = 0; i < n; i++)
    {
        cout << options[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < n / 2; i++)
    {
        int num = min(options[i], options[n - i - 1]);
        int toAdd = (num * (num + 1) / 2) % MOD;

        if (ans == 0)
        {
            ans = num;
        }
        else
        {
            ans = (ans * num + ans) % MOD;
            // ans = (ans * num) % MOD;
            ans %= MOD;
        }

        trace(i, ans, num, toAdd);
    }

    if (n == 1)
    {
        ans = options[0];
    }

    ans %= MOD;
    // ans = (ans * 2) % MOD;

    cout << "Case #" << caseNo << ": " << ans << "\n";
    caseNo++;
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