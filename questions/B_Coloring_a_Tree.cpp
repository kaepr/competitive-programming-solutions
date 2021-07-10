#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<int> adj[10005];
int visited[10005];
int color[10005];
int n, ans = 0;

void dfs(int x, int parent, int col)
{
    if (color[x] != col)
    {
        col = color[x];
        ans++;
    }

    for (auto child : adj[x])
    {
        if (child != parent)
        {
            dfs(child, x, col);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }

    dfs(1, 0, 0);
    cout << ans << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}