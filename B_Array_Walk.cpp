#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll n, k, z;
ll dp[100005][6];
vector<ll> a;

ll calc(ll i, ll kk, ll zz)
{
    if (kk == 0 || i >= n || i < 0)
        return 0;

    if (dp[i][zz] != -1)
        return dp[i][zz];

    ll val = 0;
    if (i < n)
    {
        val = max(val, a[i] + calc(i + 1, kk - 1, zz));
    }
    if (i > 0 && zz > 0)
    {
        val = max(val, a[i] + calc(i - 1, kk - 1, zz - 1));
    }
    dp[i][zz] = val;
    return val;
}

void solve()
{
    cin >> n >> k >> z;
    a.clear();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    ll ans = a[0] + calc(1, k, z);
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