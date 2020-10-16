#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int bsearch(ll arr[], ll target, ll end)
{
    ll start = 0;
    ll ans = end;
    while (start <= end)
    {
        ll mid = start + (end - start)/2;
        if (arr[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    // sort(b, b + m);

    for (ll i = 0; i < m; i++)
    {
        cout << bsearch(a, b[i], n) << " ";
    }

    return 0;
}