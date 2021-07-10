#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll k, n, a, b;
    cin >> k >> n >> a >> b;

    if (k - n * a > 0)
    {
        cout << n << "\n";
        return;
    }

    k = k - n * a;
    k = -k;
    // ++k;

    ll diff = a - b;
    ll turns = (k + diff ) / diff;
    if (turns > n)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << n - turns << "\n";
    }
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