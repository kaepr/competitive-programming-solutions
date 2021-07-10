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
    ll n, W;
    cin >> n >> W;
    vector<ll> v;
    map<ll, ll, greater<ll>> mp;
    priority_queue<pair<int, int>> p;
    ll sum = 0;
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        st.insert(x);
        v.PB(x);
        mp[x]++;
    }

    // if (sum % W == 0)
    // {
    //     cout << sum / W << "\n";
    // }
    // else
    // {
    //     cout << sum / W + 1 << "\n";
    // }

    // cout << (sum / W) << "\n";

    ll height = 0, currFill = W;

    ll largestPower = 1;
    while (largestPower <= currFill)
    {
        largestPower *= 2;
    }
    largestPower /= 2;

    ll sz = v.size();

    ll times = 3;

    while (true)
    {
        ll ans = largestPower;

        ll thisTurn = 0;

        while (currFill > 0 && ans >= 1)
        {
            if (mp[ans] > 0 && (currFill - ans >= 0))
            {
                mp[ans]--;
                sz--;
                currFill -= ans;
                thisTurn += ans;
            }
            else
            {
                ans /= 2;
            }
        }

        // int cnt = 0;
        // for (auto x : mp)
        // {
        //     if (x.second > 0)
        //     {
        //         cnt++;
        //         break;
        //     }
        // }
        if (sz > 0)
        {
            //nothing, it continues
            height++;
            currFill = W;
        }
        else
        {
            if (thisTurn)
            {
                height++;
            }
            break;
        }
        // times--;
    }
    // trace(height);
    cout << height << "\n";
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