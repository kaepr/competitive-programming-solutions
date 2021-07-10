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
    ll maxx = 100000005;
    ll limit = sqrt(maxx) + 1;
    ll low = limit, high = 2 * limit;
    vector<ll> prime;
    vector<ll> prime2;
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));
    for (ll p = 2; p * p < limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i = p * p; i < limit; i += p)
            {
                mark[i] = false;
            }
        }
    }
    for (int p = 2; p < limit; p++)
    {
        if (mark[p] == true)
        {
            prime.PB(p);
            prime2.PB(p);
        }
    }

    while (low < maxx)
    {
        if (high >= maxx)
        {
            high = maxx;
        }
        memset(mark, true, sizeof(mark));
        for (ll i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(low / prime[i]) * prime[i];
            if (loLim < low)
            {
                loLim += prime[i];
            }

            for (ll j = loLim; j < high; j += prime[i])
            {
                mark[j - low] = false;
            }
        }

        for (ll i = low; i < high; i++)
        {
            if (mark[i - low])
            {
                prime2.PB(i);
            }
        }

        low += limit;
        high += limit;
    }
    // for (auto x : prime2)
    // {
    //     cout << x << " ";
    // }
    for (int i = 0; i < prime2.size(); i += 100)
    {
        cout << prime2[i] << "\n";
    }
    cout << "\n";
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