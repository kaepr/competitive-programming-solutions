#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    string s;
    cin >> s;
    int Wcnt = 0, Lcnt = 0;
    vi losing_streak;
    int winning_streak = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            Wcnt++;
            if (i == 0 || s[i - 1] == 'L')
            {
                winning_streak++;
            }
        }
        else
        {
            Lcnt++;
            if (i == 0 || s[i - 1] == 'W')
            {
                losing_streak.pb(0);
            }
            losing_streak.back()++;
        }
    }

    if (k + Wcnt >= n)
    {
        cout << n * 2 - 1 << "\n";
        return;
    }

    if (Wcnt == 0)
    {
        if (k == 0)
            cout << 0 << "\n";
        else
        {
            cout << 2 * k - 1 << "\n";
        }
        return;
    }
    if (s[0] == 'L')
    {
        losing_streak[0] = 1e8;
    }
    if (s[n - 1] == 'L')
        losing_streak.back() = 1e8;

    sort(losing_streak.begin(), losing_streak.end());
    Wcnt += k;
    for (int ls : losing_streak)
    {
        if (ls > k)
            break;
        k -= ls;
        winning_streak--;
    }
    cout << 2 * Wcnt - winning_streak << "\n";
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