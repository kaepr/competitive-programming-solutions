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

const ll N = 1e5 + 10;
ll node[4 * N];

void update(ll v, ll tl, ll tr, ll id, ll val)
{
    if (tl == id && tr == id)
    {
        node[v] = val;
        return;
    }

    if (id > tr || id < tl)
    {
        return;
    }

    ll tm = tl + (tr - tl) / 2;
    update(2 * v, tl, tm, id, val);
    update(2 * v + 1, tm + 1, tr, id, val);

    node[v] = node[2 * v + 1] + node[2 * v];
}

ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl > r || tr < l)
    {
        return 0;
    }

    if (l <= tl && tr <= r)
    {
        //l ... tl ... tr ... r
        // cout << "HAPPENS\n";
        return node[v];
    }
    ll tm = tl + (tr - tl) / 2;
    ll ans = 0;
    ans += query(2 * v, tl, tm, l, r);
    ans += query(2 * v + 1, tm + 1, tr, l, r);
    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        update(1, 0, N - 1, i, x);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << node[i] << " ";
    // }
    // cout << "\n";
    while (m > 0)
    {
        //1 = update
        //2 = query
        ll q;
        cin >> q;
        if (q == 1)
        {

            ll idx, val;
            cin >> idx >> val;
            // trace(q, idx, val);
            update(1, 0, N - 1, idx, val);
        }
        else if (q == 2)
        {
            ll l, r;
            cin >> l >> r;
            // trace(q, l, r);
            cout << query(1, 0, N - 1, l, r - 1) << "\n";
        }
        m--;
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