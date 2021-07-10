#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    // cout << "\n";

    int freq[11];

    for (int i = 0; i < 11; i++)
        freq[i] = 0;

    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << freq[i] << " ";
    // }
    // cout << "\n";

    map<int, int> mp;
    for (int i = 1; i <= 10; i++)
    {
        mp[freq[i]]++;
    }

    // for (auto x : mp)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }

    int ans = 0;
    int sol = INT_MAX;
    for (auto x : mp)
    {
        if (x.second >= ans && x.first > 0)
        {

            if (x.second > ans)
            {
                sol = x.first;
            }
            else
            {
                sol = min(sol, x.first);
            }
            ans = x.second;
        }
    }
    // cout << ans << "\n";
    cout << sol << "\n";
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