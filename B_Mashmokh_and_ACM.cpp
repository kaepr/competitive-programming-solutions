#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int dp[2005][2005];
vector<int> divisors[2005];
int n, k;

int solve(int num, int m)
{
    if (num == 1)
        return 1;

    if (dp[num][m] != -1)
        return dp[num][m];

    int n = divisors[m].size(), ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += solve(num - 1, divisors[m][i]) % mod;
        ret %= mod;
    }
    dp[num][m] = ret;
    return ret;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 2000; i++)
    {
        for (int j = i; j <= 2000; j += i)
        {
            divisors[j].push_back(i);
        }
    }

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(k, i) % mod;
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}