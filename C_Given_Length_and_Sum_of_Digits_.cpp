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

int maxSumPossible(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += 9;
        n /= 10;
    }
    return ans;
}

int smallestPossible(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += 1;
        n /= 10;
    }
    return ans;
}

int sumDigit(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve()
{
    int m, s;
    cin >> m >> s;
    vi num, num1;
    if (s == 0 && m != 1)
    {
        cout << -1 << " " << -1 << "\n";
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int dig = min(9, s);
        num.PB(dig);
        num1.PB(dig);
        s -= dig;
    }

    if (s != 0)
    {
        cout << -1 << " " << -1 << "\n";
        return;
    }

    sort(num.begin(), num.end());

    // for (auto x : num)
    // {
    //     cout << x;
    // }
    if (num[0] == 0)
    {
        int index = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] != 0)
            {
                index = i;
                break;
            }
        }
        num[0]++;
        num[index]--;
    }

    for (auto x : num)
    {
        cout << x;
    }

    cout << " ";

    // sort(num.begin(), num.end());
    // reverse(num.begin(), num.end());
    for (auto x : num1)
    {
        cout << x;
    }
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