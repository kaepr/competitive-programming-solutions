#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> lastind;
    int i = 1, ans = 0;
    for (int j = 1; j <= n; j++)
    {
        i = max(i, lastind[a[j]] + 1);
        ans = max(ans, j - i + 1);
        lastind[a[j]] = j;
    }
    cout << ans << "\n";
    return 0;
}