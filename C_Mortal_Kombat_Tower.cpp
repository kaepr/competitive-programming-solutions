#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int MAXN = 200005;
int a[200005];
int n;
int dp[MAXN][2];

int ans(int i, int player)
{
    //0 means friends
    //1 means my play

    if (i >= n)
    {
        dp[i][player] = 0;
        return dp[i][player];
    }

    if (dp[i][player] != -1)
        return dp[i][player];

    if (player)
    {
        return dp[i][player] = min(ans(i + 1, !player), ans(i + 2, !player));
    }
    else
    {
        int sol = 1e9;
        if (i < n && a[i] == 1)
            sol = min(sol, ans(i + 1, !player) + 1);

        if (i < n && a[i] == 0)
            sol = min(sol, ans(i + 1, !player));

        if (i + 1 < n && a[i] == 0 && a[i + 1] == 0)
            sol = min(sol, ans(i + 2, !player));

        if (i + 1 < n && a[i] == 1 && a[i + 1] == 1)
            sol = min(sol, ans(i + 2, !player) + 2);

        if (i + 1 < n && a[i] == 1 && a[i + 1] == 0)
            sol = min(sol, ans(i + 2, !player) + 1);

        if (i + 1 < n && a[i] == 0 && a[i + 1] == 1)
            sol = min(sol, ans(i + 2, !player) + 1);

        dp[i][player] = sol;
        return dp[i][player];
    }
}

void solve()
{
    // memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sol = ans(0, 0);

    cout << dp[0][0] << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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