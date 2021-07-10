#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pos;
    cin >> n >> pos;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    int l, r = pos;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            int dist = i - pos;
            int j = pos - dist;
            if (j < 1 || j > n || a[i] == a[j])
                ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}