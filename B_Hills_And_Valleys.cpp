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

int n;
int a[300005];

bool isHill(int i)
{
    if (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1])
        return true;

    return false;
}

bool isValley(int i)
{
    if (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1])
        return true;

    return false;
}

int calc(int i)
{
    int val = isHill(i - 1) + isHill(i) + isHill(i + 1) + isValley(i - 1) + isValley(i) + isValley(i + 1);
    return val;
}

void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (isHill(i) || isValley(i))
            ans++;
    }

    // trace(ans);
    int maxChange = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int curr = calc(i);
        int prev = a[i - 1], next = a[i + 1], mid = a[i];
        a[i] = max(a[i - 1], a[i + 1]);
        int newone = calc(i);
        a[i] = min(a[i - 1], a[i + 1]);
        int newtwo = calc(i);

        maxChange = max(maxChange, curr - newone);
        maxChange = max(maxChange, curr - newtwo);

        a[i] = mid;
    }
    cout << max(0, ans - maxChange) << "\n";
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