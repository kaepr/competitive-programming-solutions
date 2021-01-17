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

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int preSum[n + 1];
    memset(preSum, 0, sizeof(preSum));
    preSum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            preSum[i + 1] = preSum[i] + 1;
        }
        else
        {
            preSum[i + 1] = preSum[i] - 1;
        }
    }

    int preMin[n + 1];
    int preMax[n + 1];
    preMax[0] = 0;
    preMin[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        preMin[i] = min(preMin[i - 1], preSum[i]);
        preMax[i] = max(preMax[i - 1], preSum[i]);
    }

    int sufMax[n + 2], sufMin[n + 2];
    memset(sufMax, 0, sizeof(sufMax));
    memset(sufMin, 0, sizeof(sufMin));
    sufMax[n + 1] = preSum[n];
    sufMin[n + 1] = preSum[n];
    int cur = preSum[n];

    for (int i = n; i >= 0; i--)
    {

        sufMax[i] = max(preSum[i], sufMax[i + 1]);
        sufMin[i] = min(preSum[i], sufMin[i + 1]);
    }

    while (m > 0)
    {
        int l, r;
        cin >> l >> r;

        int a = preSum[l - 1];
        int b = preSum[r + 1];

        int d1 = sufMax[r + 1] - preSum[r];
        int d2 = sufMin[r + 1] - preSum[r];

        int maxx = max(preMax[l - 1], a + d1);
        int minn = min(preMin[l - 1], a + d2);

        cout << maxx - minn + 1 << "\n";
        m--;
    }
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