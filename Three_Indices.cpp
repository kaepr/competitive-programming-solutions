#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int aa = 0, bb = 0, cc = 0;
    int f = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (f == 0)
                {
                    if (a[i] < a[j] && a[j] > a[k])
                    {
                        f = 1;
                        aa = i;
                        bb = j;
                        cc = k;
                    }
                }
            }
        }
    }
    if (f)
    {
        cout << "YES\n";
        cout << aa << " " << bb << " " << cc << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
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