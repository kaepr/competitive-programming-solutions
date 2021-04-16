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
    vector<ll> a;
    set<ll> st;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
        a.PB(x);
        // mp[x]++;
    }
    sort(a.begin(), a.end());
    vector<ll> d;
    set<ll> dt;
    for (ll i = 1; i < n; i++)
    {
        d.PB(a[i] - a[i - 1]);
        dt.insert(a[i] - a[i - 1]);
        mp[a[i] - a[i - 1]]++;
    }

    if (n == 1)
    {
        cout << -1 << "\n";
        return;
    }
    if (st.size() == 1)
    {
        cout << 1 << "\n";
        cout << a[0] << "\n";
        return;
    }

    if (dt.size() == 1)
    {
        //proper AP

        if (n == 2)
        {
            if ((a[1] + a[0]) % 2 == 0)
            {
                cout << 3 << "\n";
                cout << a[0] - d[0] << " " << ((a[1] + a[0]) / 2) << " " << a[1] + d[0] << "\n";
                return;
            }
            else
            {
                cout << 2 << "\n";
                cout << a[0] - d[0] << " " << a[1] + d[0] << "\n";
                return;
            }
        }
        else
        {
            cout << 2 << "\n";
            cout << a[0] - d[0] << " " << a[n - 1] + d[1] << "\n";
            return;
        }
    }

    ll actualD = 0, fakeD = 0;
    int cnt = 0;
    for (auto x : mp)
    {
        // cout << x.first << " " << x.second << "\n";
        if (cnt == 0)
        {
            actualD = x.first;
        }
        else
        {
            fakeD = x.first;
        }
        cnt++;
        if (cnt > 1)
        {
            break;
        }
    }
    // cout << "\n";

    int fakeCnt = 0, realCnt = 0, other = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] == fakeD)
        {
            ans = a[i - 1] + actualD;
            if ((ans + actualD) == a[i])
            {
                fakeCnt++;
            }
            // trace(a[i - 1], a[i]);
        }
        else if (a[i] - a[i - 1] == actualD)
        {
            realCnt++;
        }
        else
        {
            other++;
        }
    }

    if (fakeCnt == 1 && other == 0)
    {
        cout << 1 << "\n";
        cout << ans << "\n";
        return;
    }

    cout << "0\n";
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