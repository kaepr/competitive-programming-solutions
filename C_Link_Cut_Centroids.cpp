#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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

const int MAXN = 1e5 + 5;

vector<int> arr[MAXN];
int sz[MAXN];
int n;
vi centroid;

void dfs(int src, int parent)
{
    bool isCentroid = true;
    sz[src] = 1;
    for (auto u : arr[src])
    {
        if (u != parent)
        {
            dfs(u, src);
            sz[src] += sz[u];
            if (sz[u] > n / 2)
                isCentroid = false;
        }
    }
    if (n - sz[src] > n / 2)
        isCentroid = false;

    if (isCentroid)
    {
        centroid.pb(src);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        arr[i].clear();
        sz[i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].pb(y);
        arr[y].pb(x);
    }

    centroid.clear();
    dfs(1, -1);

    vector<pair<int, int>> ans;
    if (centroid.size() == 1)
    {
        ans.pb(mp(1, arr[1][0]));
        ans.pb(mp(1, arr[1][0]));
    }
    else if (centroid.size() == 2)
    {
        for (auto x : arr[centroid[0]])
        {
            if (x != centroid[1])
            {
                ans.pb(mp(x, centroid[0]));
                ans.pb(mp(x, centroid[1]));
                break;
            }
        }
    }

    for (auto x : ans)
    {
        cout << x.first << " " << x.second << "\n";
    }
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