#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (a[i] >= 0)
            {
                a[i] = (-1) * a[i];
            }
            else
            {
                // do nothing
            }
        }
        else
        {
            if (a[i] >= 0)
            {
                //do nothing
            }
            else
            {
                a[i] = abs(a[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    cout << "\n";
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