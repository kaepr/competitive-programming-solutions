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

ll n;
vector<ll> arr[100005];
ll w[100005];

void solve()
{
    vector<pair<ll, ll>> v;
    cin >> n;
    // trace(n);
    // vi w;
    for (ll i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    // cout << "WEIGHTS\n";
    // for (ll i = 1; i <= n; i++)
    //     cout << w[i] << " ";

    // cout << "\n";

    map<ll, ll> mp;

    for (ll i = 1; i <= n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
        arr[a].PB(b);
        arr[b].PB(a);
    }

    // cout << "SIZES\n";

    // for (auto x : mp)
    // {
    //     trace(x.first, x.second);
    // };

    vector<pair<ll, ll>> vInfo;
    for (ll i = 0; i < n; i++)
    {
        ll weight = w[i + 1];
        ll edges = mp[i + 1];
        vInfo.PB(MP(weight, edges));
    }

    sort(vInfo.begin(), vInfo.end());
    reverse(vInfo.begin(), vInfo.end());

    // for (ll i = 0; i < n; i++)
    // {
    //     cout << i + 1 << " " << vInfo[i].F << " " << vInfo[i].S << "\n";
    // }

    vector<ll> ans;
    ll totalSum = 0;
    ll colorHandled = 0;
    vi wts;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < vInfo[i].S - 1; j++)
        {
            wts.PB(vInfo[i].F);
        }
        sum += vInfo[i].F;
    }
    // for (ll i = 1; i <= n - 1; i++)
    // {
    //     ll currSum = 0;
    //     ll colorTimes = i;
    //     bool happen = true;
    //     trace(colorTimes);
    //     for (ll j = 0; j < n; j++)
    //     {

    //         if (vInfo[j].S > 0)
    //         {
    //             currSum += vInfo[j].F;
    //             vInfo[j].S--;
    //         }

    //         // if (happen)
    //         // {
    //         //     ll possibleTimes = 1;
    //         //     while (true)
    //         //     {
    //         //         currSum += vInfo[j].F;
    //         //         possibleTimes--;
    //         //         vInfo[j].S = vInfo[j].S - 1;
    //         //         trace(vInfo[j].F, vInfo[j].S);
    //         //         break;
    //         //     }
    //         //     happen = false;
    //         // }
    //     }
    //     trace(currSum);
    //     for (ll i = 0; i < n; i++)
    //     {
    //         cout << i + 1 << " " << vInfo[i].F << " " << vInfo[i].S << "\n";
    //     }
    //     // currSum += totalSum;
    //     colorHandled++;
    //     totalSum += currSum;
    //     ans.PB(totalSum);
    // }
    ans.PB(sum);
    sort(wts.begin(), wts.end());
    reverse(wts.begin(), wts.end());
    for (ll i = 0; i < min(n,(ll) wts.size()); i++)
    {
        sum += wts[i];
        ans.PB(sum);
    }
    for (auto x : ans)
    {
        cout << x << " ";
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

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}