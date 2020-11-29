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

vector<ll> squares, cubes;

bool check[2002] = {false};

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto x : mp)
    {
        v.PB(x.first);
    }

    // for (auto x : v)
    // {
    //     cout << x << "\n";
    // }

    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int freq = mp[v[i]];
        // trace(freq);
        if (freq > 1 && check[v[i] + v[i]])
        {
            ans += freq * (freq - 1) / 2;
        }
        for (int j = i + 1; j < v.size(); j++)
        {
            if (check[v[i] + v[j]])
            {
                ans += freq * mp[v[j]];
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 1; i <= 2002; i++)
    {
        if (i * i <= 2000)
            check[i * i] = true;

        if (i * i * i <= 2000)
            check[i * i * i] = true;
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