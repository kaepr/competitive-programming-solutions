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

void solve()
{
    ll n, s, k;
    cin >> n >> s >> k;
    vi v;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v.PB(x);
    }

    sort(v.begin(), v.end());

    if (!binary_search(v.begin(), v.end(), s))
    {
        cout << 0 << "\n";
        return;
    }

    int rightDistance = 0;
    int index = upper_bound(v.begin(), v.end(), s) - v.begin();
    index--;
    int orig = v[index];
    int tempElement = v[index];

    bool f = false;
    while (true)
    {
        tempElement++;
        if (!binary_search(v.begin(), v.end(), tempElement))
        {
            rightDistance = tempElement - orig;
            f = true;
            break;
        }
    }

    if (tempElement >= 1 && tempElement <= n)
    {
    }
    else
    {
        rightDistance = 1e9;
    }

    tempElement = orig;
    f = false;
    int leftDistance = 0;
    while (true)
    {
        tempElement--;
        if (!binary_search(v.begin(), v.end(), tempElement))
        {
            leftDistance = orig - tempElement;
            f = true;
            break;
        }
    }

    if (tempElement >= 1 && tempElement <= n)
    {
    }
    else
    {
        leftDistance = 1e9;
    }

    cout << min(leftDistance, rightDistance) << "\n";
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