#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<int> adj[1005];
int visited[1005];
vector<int> nope[1005];
int visited2[1005];

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        nope[x].push_back(y);
        nope[y].push_back(x);
        visited[x] = 1;
        visited[y] = 1;
    }
    int last;
    for (int i = 1; i <= n; i++)
        if (visited[i] != 1)
            last = i;

    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (last == i)
        {
            //continue
        }
        else
        {
            cout << last << " " << i << "\n";
            
        }
    }

    return 0;
}