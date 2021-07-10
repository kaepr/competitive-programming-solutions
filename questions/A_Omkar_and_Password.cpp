#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ptr = 0;

    set<int> dist;
    for (int i = 0; i < n; i++)
    {
        dist.insert(a[i]);
    }
    if (dist.size() == 1)
    {
        cout << n << "\n";
    }
    else
    {
        cout << 1 << "\n";
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