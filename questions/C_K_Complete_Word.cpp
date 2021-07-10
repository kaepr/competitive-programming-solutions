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
    int n, k;
    cin >> n >> k;
    // n is divisible by k

    vector<vector<int>> vk;
    string s;
    cin >> s;

    // can contain maximum of 'k' characters

    int ans = 0, num_group = n / k;

    for (int i = 0; i < k; i++)
    {
        vi temp;
        map<char, int> mp;
        int extra = 0;
        for (int j = i; j < n; j += k)
        {
            mp[s[j]]++;
            if (k % 2 == 1 && i == (num_group / 2))
            {
                char c1 = s[j], c2 = s[(i + 1) * k - j];
                trace(i, j);
                trace(c1, c2);
                if (c1 == c2)
                {
                    trace("hello");
                }
            }
        }

        int max_freq = 0, total = 0;
        for (auto x : mp)
        {
            total += x.second;
            max_freq = max(max_freq, x.second);
        }
        ans += (total - max_freq);
    }

    cout << ans << "\n";
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