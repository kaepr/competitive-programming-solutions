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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll sheepCnt = 0;

    map<ll, ll> mp;
    ll sCnt = 0;
    ll index1 = n;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            index1 = min(index1, i);
            mp[sheepCnt] = i;
            sheepCnt++;
        }
    }

    if (sheepCnt == 0 || sheepCnt == n || sheepCnt == 1)
    {
        cout << 0 << "\n";
        return;
    }

    // form blocks of  ....***.... ,

    ll k = sheepCnt;
    // for (auto x : mp)
    // {
    //     trace(x.first, x.second);
    // }

    // total possible groups are n - k + 1

    ll start = index1;
    ll ans = 1e18 + 10;
    for (ll i = 0; i < n - k + 1; i++)
    {
        ll curr_sum = 0;
        ll ptr = start;
        for (auto x : mp)
        {
            // trace(x.first, x.second, i);
            curr_sum += abs(x.second - ptr);
            ptr++;
        }
        ans = min(ans, curr_sum);
        start++;
    }
    // trace(ans);
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