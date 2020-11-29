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
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    int elm = 0;
    int ans = 0;
    int lastElm = a[0];
    //mp[a[0]]++;
    elm = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == lastElm)
        {
            //continue
        }
        else
        {
            mp[a[i]]++;
            lastElm = a[i];
        }
    }
    int last = a[n - 1];
    for (auto x : st)
    {
        if (x == last)
        {
            //ignore
        }
        else
        {
            mp[x]++;
        }
    }

    int sol = INT_MAX;
    for (auto x : mp)
    {
        // trace(x.first);
        // trace(x.second);
        sol = min(sol, x.second);
    }
    if (sol == INT_MAX)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << sol << "\n";
    }

    // cout << "NEW CASE\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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