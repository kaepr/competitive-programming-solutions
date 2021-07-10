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

// int numDigits()

void solve()
{
    int x;
    cin >> x;
    if (x > 45)
    {
        cout << -1 << "\n";
        return;
    }

    if (x < 10)
    {
        cout << x << "\n";
        return;
    }

    vi d;
    // d.PB(9);
    // d.PB(8);

    for (int i = 9; i >= 1; i--)
    {
        d.PB(i);
    }

    vi v;
    int index = 0;
    // x -= 9;
    // v.PB(9);
    // index++;

    while (x > d[index])
    {
        x -= d[index];
        v.PB(d[index]);
        index++;
    }
    v.PB(x);

    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << "";
    }
    cout << "\n";

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