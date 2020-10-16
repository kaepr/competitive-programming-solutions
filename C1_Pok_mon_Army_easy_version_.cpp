#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const ll MAXN = 300005;
ll a[MAXN];
ll n, q;
ll dp[MAXN][2];

ll sum(ll l, ll addSub)
{
    if (dp[l][addSub] != -1)
    {
        return dp[l][addSub];
    }

    if (l >= n)
    {
        dp[l][addSub] = 0;
        return dp[l][addSub];
        // return 0;
    }

    if (addSub)
    {
        dp[l][addSub] = max(a[l] + sum(l + 1, 0), sum(l + 1, 1));
        return dp[l][addSub];
    }
    else
    {
        dp[l][addSub] = max(-1 * a[l] + sum(l + 1, 1), sum(l + 1, 0)); 
        return dp[l][addSub];
    }
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> q;

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    while (q > 0)
    {
    }

    ll ans =sum(0, 1);
    cout << ans << "\n";
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