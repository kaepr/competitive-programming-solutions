#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int s1 = a[i], s2 = a[i + 1];
        int s3 = abs(s1 - s2) - 1;
        sum += s3;
    }
    cout << sum << "\n";
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