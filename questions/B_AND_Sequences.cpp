#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const ll MOD = 1e9 + 7;

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
const ll maxn = 2e5 + 10;
ll fact[maxn];

void solve()
{
    // trace(1 & 2);
    ll n;
    cin >> n;
    vector<ll> v;
    map<ll, ll> mp;
    set<ll> st;
    bool zero = false;
    ll val;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (i == 0)
        {
            val = x;
        }
        val = val & x;
        if (x == 0)
        {
            zero = true;
        }
        mp[x]++;
        st.insert(x);
        v.PB(x);
    }
    // trace(val);
    ll cnt = mp[val];

    if (cnt <= 1)
    {
        cout << 0 << "\n";
        return;
    }

    // cout << fact[n - 2] << "\n";

    if (st.size() == 1)
    {
        cout << fact[n] << "\n";
        return;
    }

    //ways of arranging middle positions
    // trace(cnt);
    // ll ans = ((fact[n - 2] % MOD) * (cnt % MOD) * ((cnt - 1) % MOD)) % MOD;
    // ll ans = ((fact[n - 2] % MOD) * (cnt * cnt - 1) % MOD) % MOD;
    // trace(n, cnt);
    ll ans = (fact[n - 2]) % MOD * ((cnt * (cnt - 1)) % MOD) % MOD;
    // ans *= (cnt - 2) % MOD;
    // ans *= cnt;
    // ans %= MOD;
    // ans *= (cnt - 1);
    // ans %= MOD;
    // trace(fact[n - 2]);

    if (ans <= 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < maxn; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        fact[i] %= MOD;
    }

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}