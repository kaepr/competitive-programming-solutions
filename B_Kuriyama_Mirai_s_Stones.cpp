#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const ll N = 100005;

ll a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a + 1, a + n + 1);
    for(ll i=1; i<=n; i++){
        b[i] += b[i-1];
        a[i] += a[i-1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << b[r] - b[l - 1] << "\n";
        }
        else
        {
            cout << a[r] - a[l - 1] << "\n";
        }
    }

    return 0;
}