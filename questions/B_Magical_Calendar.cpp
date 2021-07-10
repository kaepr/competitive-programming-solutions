#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, r;
    cin >> n >> r;
    ll res = 0;
    if (n <= 1)
    {
        cout << "1\n";
        return;
    }

    if (n <= r)
    {
        r = n - 1;
        res = 1;
    }

    cout<<res + (( 1 + r) * (r)/2)<<"\n";
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