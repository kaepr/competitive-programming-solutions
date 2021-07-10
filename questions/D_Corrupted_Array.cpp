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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> b;
    for (ll i = 0; i < n + 2; i++)
    {
        ll x;
        cin >> x;
        b.PB(x);
    }

    sort(b.begin(), b.end());
    // map<ll, ll> mp;

    ll total_sum = 0;
    for (auto x : b)
    {
        // mp[x]++;
        total_sum += x;
    }

    ll sum_till_n = 0;
    for (ll i = 0; i < n; i++)
    {
        sum_till_n += b[i];
    }
    ll bsz = n + 2;

    ll pre_sum[bsz];
    pre_sum[0] = b[0];
    for (ll i = 1; i < b.size(); i++)
    {
        pre_sum[i] = pre_sum[i - 1] + b[i];
    }

    if (sum_till_n == b[bsz - 1] || sum_till_n == b[bsz - 2])
    {
        // trace(sum_till_n);
        for (ll i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
        return;
    }

    ll yess = pre_sum[bsz - 2];
    // trace(yess);
    ll index = -1;
    for (ll i = 0; i < bsz - 1; i++)
    {
        //do not take b[i]
        ll rem_sum = yess - b[i];
        if (rem_sum == b[bsz - 1])
        {
            index = i;
            break;
        }
    }
    // trace(index);
    // trace(yess);
    if (index == -1)
    {
        cout << "-1\n";
        return;
    }
    for (ll i = 0; i < bsz - 1; i++)
    {
        if (index != i)
        {
            cout << b[i] << " ";
        }
    }
    cout << "\n";
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