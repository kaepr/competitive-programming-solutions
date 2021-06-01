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

// bool chk(ll num, ll pow)
// {
//     if (num == 0)
//     {
//         return true;
//     }

//     while (num >= 1)
//     {
//         if (num == 1)
//         {
//             break;
//         }
//         if (num % pow != 0)
//         {
//             return false;
//         }
//         num /= pow;
//     }

//     return true;
// }

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    ll zeros = 0;
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll c[60] = {0};

    for (ll i = 0; i < n; i++)
    {
        ll j = 0;
        while (a[i] > 0)
        {
            c[j] += a[i] % k;
            j++;
            a[i] /= k;
        }
    }

    for (ll i = 0; i < 60; i++)
    {
        if (c[i] > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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