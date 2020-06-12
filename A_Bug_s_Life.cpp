#include <bits/stdc++.h>
using namespace std;

vector<int> arr[2001];
int vis[2001], col[2001];

bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;

    for(int child : arr[node]){
        if(vis[child] == 0){
            bool res = dfs(child, c ^ 1);
            if(res == false)
                return false;
        }else if(col[node] == col[child]){
            return false;
        }
    }

    return true;
}

int main()
{

    int t, n, m, a, b;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            arr[i].clear(), vis[i] = 0, col[i] = 0;

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                bool res = dfs(i, 0);

                if (res == false)
                {
                    flag = false;
                }
            }
        }

        cout << "Scenario #" << tc << ":\n";
        if (flag)
        {
            cout << "No suspicious bugs found!\n";
        }
        else
        {
            cout << "Suspicious bugs found!\n";
        }
    }

    return 0;
}