#include <bits/stdc++.h>
using namespace std;
 
vector<int> arr[100001];
int vis[100001];
int dist[100001] = {INT_MAX};
int pred[100001] = {-1};
int pathFound = 0;
vector<int> path;
 
void bfs(int node, int final)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;
 
    while (!q.empty())
    {
        int curr = q.front();
        //if (curr == final)
        //{
        //    pathFound = 1;
        //    return;
        //}
        q.pop();
        for (int child : arr[curr])
        {
            if (vis[child] == 0)
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
                pred[child] = curr;
 
                if (child == final)
                {
                    pathFound = 1;
                    return;
                }
            }
        }
    }
}
 
void printPath(int dest)
{
    int crawl = dest;
    path.push_back(crawl);
 
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    for (int i = path.size() - 2; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
 
    bfs(1, n);
 
    if (pathFound)
    {
        cout << dist[n] + 1 << "\n";
        printPath(n);
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
 
    return 0;
}