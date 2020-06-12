#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int cnt[n + m - 1][2] = {0};
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt[i + j][arr[i][j]]++;

        for (int i = 0; i <= n + m - 2; i++)
        {
            int j = n + m - 2 - i;
            if (i <= j)
                continue;

            ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
        }
        cout << ans << "\n";
    }
    return 0;
}