#include <bits/stdc++.h>
using namespace std;

vector<int> arr[1001];
int vis[1001], dist[1001];

void dfs(int n, int d)
{

    vis[n] = 1;
    dist[n] = d;

    for (int child : arr[n])
        if (vis[child] == 0)
            dfs(child, dist[n] + 1);
}

int main()
{
    int n, q, a, b;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1, 0);

    int ans = -1, min_dist = 1e9;
    cin >> q;
    while (q--)
    {
        int girl_city;
        cin >> girl_city;

        if (dist[girl_city] < min_dist)
        {
            min_dist = dist[girl_city];
            ans = girl_city;
        }
        else if (dist[girl_city] == min_dist && girl_city < ans)
            ans = girl_city;
    }
    cout << ans;

    return 0;
}