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

const ll N = 2e5 + 5;
ll n, k;
vector<ll> adj[N];
ll vis[N];
// vector<ll> vals;
ll sz[N];
ll dep[N];
ll dp[N];
vector<ll> v;

void dfs(ll node, ll level)
{
    vis[node] = 1;
    dp[node] = 1;
    dep[node] = level;

    for (auto x : adj[node])
    {
        if (vis[x] == 0)
        {
            // vals.push_back(val + 1);
            dfs(x, level + 1);
            dp[node] += dp[x];
        }
    }
}

void solve()
{
    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    dfs(1, 1);

    for (ll i = 1; i <= n; i++)
    {
        v.PB(dp[i] - dep[i]);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll sum = 0;
    for (ll i = 0; i < (n - k); i++)
        sum += v[i];
    cout << sum << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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