#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    int n;
    cin >> n;

    map<int, int> xpts;
    map<int, int> ypts;

    for (int i = 0; i < 4 * n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        xpts[a]++;
        ypts[b]++;
    }

    int X, Y;
    for (auto i : xpts)
    {
        if (i.second % 2 != 0)
        {
            X = i.first;
        }
    }

    for (auto i : ypts)
    {
        if (i.second % 2 != 0)
        {
            Y = i.first;
        }
    }

    cout << X << " " << Y << "\n";
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