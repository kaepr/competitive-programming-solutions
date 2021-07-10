#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int board[105][105];
int vis[105][105];
int n, m, x, y;

void printColumnTop(int col)
{
    for (int i = 1; i <= n; i++)
        if (vis[i][col] == 0)
        {
            cout << i << " " << col << "\n";
            vis[i][col] = 1;
        }
}

void printColumnBottom(int col)
{
    for (int i = n; i >= 1; i--)
        if (vis[i][col] == 0)
        {
            cout << i << " " << col << "\n";
            vis[i][col] = 1;
        }
}

void solve()
{
    // for(int i=0; i<105; i++)
    //     for(int j=0; j<105; j++)
    //         grid[i][j] = 0;

    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            vis[i][j] = 0;

    // int n,m;
    cin >> n >> m;
    // int x,y;
    cin >> x >> y;

    vis[x][y] = 1;
    cout << x << " " << y << "\n";

    printColumnTop(y);
    //now at n,y
    int cnt = 0;
    //going right
    for (int i = y + 1; i <= m; i++)
    {
        if (cnt % 2 == 0)
        {
            printColumnBottom(i);
        }
        else
        {
            printColumnTop(i);
        }
        cnt++;
    }

    //going left
    for (int i = y - 1; i >= 1; i--)
    {
        if (cnt % 2 == 0)
        {
            printColumnBottom(i);
        }
        else
        {
            printColumnTop(i);
        }
        cnt++;
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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