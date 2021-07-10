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
    ll n, k;
    cin >> n >> k;
    // trace(n, k);
    string s = "";
    for (int i = 0; i <= n; i++)
    {
        s += 'a';
    }

    ll low = 1, high = n * (n + 1) / 2;

    while (low < high - 1)
    {
        ll m = low + (high - low) / 2;
        ll sum = m * (m - 1) / 2;
        // trace(m, sum, low, high);
        if (sum == k)
        {
            low = m;
            high = m;
            break;
        }
        if (sum <= k)
        {
            low = m;
        }
        else
        {
            high = m;
        }
    }
    // high--;
    // trace(k, low, high);
    s[high] = 'b';
    high--;
    ll index = k - (high) * (high - 1) / 2;
    // trace(index);
    s[index] = 'b';
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }

    cout << "\n";
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