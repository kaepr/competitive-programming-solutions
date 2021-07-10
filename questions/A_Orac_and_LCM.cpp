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

ll powmod(ll x, ll y)
{
    ll res = 1;

    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

const int MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

ll lcm(ll a, ll b)
{
    return (a * b / gcd(a, b));
}

vector<ll> primes;

void generate_primes(ll maxx)
{
    ll MAXN = 2e5 + 10;

    ll vis[maxx];
    memset(vis, 0, sizeof(vis));

    vis[0] = 0;
    vis[0] = 1;

    for (ll i = 2; i < maxx; i++)
    {

        if (!vis[i])
        {
            vis[i] = 1;
            primes.PB(i);
            for (ll j = i + i; j < maxx; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}

void solve()
{

    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.PB(x);
    }

    ll maxx = *max_element(v.begin(), v.end());

    generate_primes(maxx + 1);

    // for (auto x : primes)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    map<ll, vector<ll>> mp;

    for (auto x : v)
    {
        ll temp = x;
        ll ptr = 0;
        for (ll i = 2; i * i <= temp; i++)
        {
            if (temp % i == 0)
            {
                ll cnt = 0;
                while (temp % i == 0)
                {
                    temp /= i;
                    cnt++;
                }
                mp[i].PB(cnt);
            }
        }

        // trace(temp);
        if (temp > 1)
        {
            // cout << "hello\n";
            // number is prime, as its not divided anywhere
            mp[temp].PB(1);
        }
    }

    ll ans = 1;

    for (auto x : primes)
    {
        if (mp.find(x) == mp.end() || mp[x].size() < n - 1)
        {
            continue;
        }

        sort(mp[x].begin(), mp[x].end());
        if (mp[x].size() == n - 1)
        {
            ans *= powmod(x, mp[x][0]);
        }
        else
        {
            ans *= powmod(x, mp[x][1]);
        }
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

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}