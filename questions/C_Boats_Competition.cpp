#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    map<int, int> wts;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        wts[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int total = 0;
        for (auto j : wts)
        {
            int second = i - j.first;
            if (second >= 1 && wts.count(second))
                total += min(j.second, wts[second]);
        }
        total = total / 2;
        ans = max(ans, total);
    }
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