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

vector<int> adj[100005];
int n, m, ans = 0;
int cats[100005];
bool vis[100005];

void dfs(int node, int cons)
{

    vis[node] = true;
    if (cons > m)
    {
        return;
    }

    if (adj[node].size() == 1 && node != 1 && cons <= m)
    {
        ans++;
        return;
    }

    for (auto child : adj[node])
    {
        int temp = cons;

        if (cats[child])
        {
            temp++;
        }
        else
        {
            temp = 0;
        }

        if (!vis[child] && temp <= m)
            dfs(child, temp);
    }
}

void solve()
{
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cats[i + 1] = x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    int c;

    if (cats[1])
    {
        // cout << "yes\n";
        c = 1;
    }
    else
    {
        c = 0;
    }

    dfs(1, c);
    cout << ans << "\n";
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