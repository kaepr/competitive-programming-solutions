#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<pair<int, int>> w;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        w.push_back(make_pair(a[i], 1));
    }
    int ans = 0;
    int f = 0;
    int cnt = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << w[i].first << " " << w[i].second << "\n";
    // }

    for (int i = 0; i < n; i++)
        if (a[i] > k)
        {
            cout << -1 << "\n";
            return;
        }

    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        // cout << "Current sum is " << currSum << "\n";

        if (currSum > k)
        {
            cnt++;
            i = i - 1;
            currSum = 0;
        }
    }
    cout << cnt + 1 << "\n";
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