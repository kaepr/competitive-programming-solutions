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

// int a[200005];
// int dp[200005];

// void solve2()
// {

// }

void solve()
{
    // memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    bool turn = true;
    int ptr = 0;
    while (ptr < n)
    {
        if (turn)
        {
            if (ptr == n - 1)
            {
                if (a[ptr] == 1)
                {
                    ans++;
                    break;
                }
                else
                {
                    ptr++;
                    break;
                }
            }
            turn = false;
            if (a[ptr] == 1 && a[ptr + 1] == 1)
            {
                ans++;
                ptr++;
            }
            else if (a[ptr] == 1 && a[ptr + 1] == 0)
            {
                ans++;
                ptr += 2;
            }
            else if (a[ptr] == 0 && a[ptr + 1] == 1)
            {
                ptr++;
            }
            else if (a[ptr] == 0 && a[ptr + 1] == 0)
            {
                ptr += 2;
            }
        }
        else
        {
            if (ptr < n - 3 && a[ptr + 1] == 0 && a[ptr + 2] == 0)
            {
                ptr++;
            }
            else
            {
                ptr += 2;
            }

            turn = true;
        }
        // trace(ptr, ans);
    }
    cout << ans << "\n";
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