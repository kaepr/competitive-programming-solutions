#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll b[n];
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    set<int> same;
    for (int i = 0; i < n; i++)
    {
        same.insert(b[i]);
    }
    if (same.size() == 1)
    {
        cout << 0 << " " << n * (n - 1) / 2 << "\n";
        return 0;
    }

    sort(b, b + n);
    ll max_diff = b[n - 1] - b[0];
    ll small = b[0], large = b[n - 1];
    ll times = 0;
    ll first = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == small)
            first++;
    }
    ll last = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == large)
            last++;
    }
    cout << max_diff << " " << first * last << "\n";

    return 0;
}