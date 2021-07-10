#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> arr[100001];
int vis[100001], col[100001];

int dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;

    for (int child : arr[node])
    {
        if (vis[child] == 0)
        {
            bool res = dfs(child, c ^ 1);
            if (res == false)
            {
                return false;
            }
        }
        else if (col[node] == col[child])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
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

    if (flag == false)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == 0)
            {
                cout << 1 << " ";
            }
            else if (col[i] == 1)
            {
                cout << "2 ";
            }
        }
    }

    return 0;
}