#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x;
    cin >> n >> x >> m;
    //int a[n + 1] = {0};
    //a[x] = 1;
    int k = 0;
    int left = x, right = x;
    int xPos1 = x;
    int xPos2 = x;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if ((l <= xPos1 && xPos1 <= r) || (l <= xPos2 && xPos2 <= r))
        {
            left = min(left, l);
            right = max(right, r);
            xPos1 = left;
            xPos2 = right;
        }
    }

    cout << right - left + 1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}