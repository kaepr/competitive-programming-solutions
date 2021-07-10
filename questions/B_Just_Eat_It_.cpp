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
    ll sum = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (auto x : a)
    {
        sum += x;
    }
    int left = 0, right = 0;
    ll max_so_far = 0, max_till_here = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= 0)
        {
            max_till_here += a[i];
            max_so_far = max(max_so_far, max_till_here);
        }
        else if (a[i] < 0)
        {
            if (abs(a[i]) >= max_till_here)
            {
                max_till_here = 0;
            }
            else
            {
                max_till_here += a[i];
            }
        }
    }

    ll max_so_far2 = 0, max_till_here2 = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= 0)
        {
            max_till_here2 += a[i];
            max_so_far2 = max(max_so_far2, max_till_here2);
        }
        else if (a[i] < 0)
        {
            if (abs(a[i]) >= max_till_here2)
            {
                max_till_here2 = 0;
            }
            else
            {
                max_till_here2 += a[i];
            }
        }
    }

    max_so_far = max(max_so_far, max_so_far2);

    if (max_so_far >= sum)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    // trace(sum, max_so_far, max_so_far2);
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