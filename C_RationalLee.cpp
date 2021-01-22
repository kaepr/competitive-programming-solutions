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
    vector<ll> a, b;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.PB(x);
    }

    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        b.PB(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    // reverse(b.begin(), b.end());

    ll ptr1 = 0, ptr2 = n - 1;
    ll ans = 0;
    for (ll i = 0; i < b.size(); i++)
    {
        if (b[i] == 1)
        {
            ans += 2 * a[ptr1];
            ptr1++;
            b[i]--;
        }
        else
        {
            ans += a[ptr1];
            ptr1++;
            b[i]--;
            // ans += a[ptr2];
            // ptr2 -= (b[i] - 2);
        }
        // trace(ans);
    }
    //we have used elemets from 0...ptr1 - 1, so we need to assign remaining elements
    // trace(ptr1);
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != 0)
        {
            //we are at ptr1, and weight is b[i]
            //as its sorted, so take ptr1 + b[i] - 1 element
            ans += a[ptr1 + b[i] - 1];
            ptr1 = ptr1 + b[i];
        }
        // trace(ans);
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