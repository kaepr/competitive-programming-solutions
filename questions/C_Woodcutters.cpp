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

const int MAXN = 1e5 + 2;
int x[MAXN], h[MAXN];
int LEFT = 0, RIGHT = 1, STAY = 2, n;
int dp[MAXN][3];

int calc(int i, int side)
{
    if (i == 0)
        return 1;

    if (i == n - 1)
    {
        return 1 + max(calc(i - 1, RIGHT), max(calc(i - 1, LEFT), calc(i - 1, STAY)));
    }

    if (dp[i][side] != -1)
    {
        return dp[i][side];
    }

    int val = 0;
    if (side == STAY)
    {
        val = max(calc(i - 1, RIGHT), max(calc(i - 1, LEFT), calc(i - 1, STAY)));
    }
    else if (side == LEFT)
    {
        //if this condition is true, then its impossible to have it go left
        if (x[i] - h[i] <= x[i - 1])
            return 0;
        int calcRight = 0;

        //assuming it goes left, then checking the previous tree, and having it go right
        if (x[i - 1] + h[i - 1] < x[i] - h[i])
        {
            calcRight = calc(i - 1, RIGHT);
        }

        val = 1 + max(calcRight, max(calc(i - 1, LEFT), calc(i - 1, STAY)));
    }
    else
    {
        if (x[i] + h[i] >= x[i + 1])
        {
            return 0;
        }
        val = 1 + max(calc(i - 1, RIGHT), max(calc(i - 1, LEFT), calc(i - 1, STAY)));
    }
    dp[i][side] = val;
    return val;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> h[i];
    }

    cout << calc(n - 1, RIGHT);
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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