#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int freq[26] = {0};
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int p[m];
    for (int i = 0; i < m; i++)
        cin >> p[i];

    vector<int> cnt(n);
    for (int i = 0; i < m; i++)
    {
        cnt[p[i] - 1]++;
    }

    for (int i = n - 1; i > 0; --i)
    {
        cnt[i - 1] += cnt[i];
    }

    vector<int> ans(26);

    for (int i = 0; i < n; i++)
    {
        ans[str[i] - 'a'] += cnt[i];
    }

    for(int i=0; i<n; i++){
        ans[str[i] - 'a']++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}