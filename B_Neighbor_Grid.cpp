#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[305][305];
int n, m;
bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;

    return false;
}

void solve()
{
    cin >> n >> m;
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            int cnt = 0;
            if (check(i + 1, j))
                cnt++;
            if (check(i - 1, j))
                cnt++;
            if (check(i, j + 1))
                cnt++;
            if (check(i, j - 1))
                cnt++;

            if (a[i][j] > cnt)
            {
                f = 0;
            }
            else
            {
                a[i][j] = cnt;
            }
        }
    }

    if (f)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}