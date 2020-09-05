#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll pre[n];
    pre[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = a[i] + pre[i - 1];
    }

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        ll ans = 0;
        ll l = 0, r = n;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            // cout << "mid is " << mid << " and value here is " << pre[mid] << "\n";
            if (pre[mid] == x)
            {
                ans = max(ans, mid);
                break;
            }
            if (pre[mid] > x)
            {
                // cout<<"goes to right\n";
                if(x > pre[mid - 1] && x < pre[mid]){
                    ans = mid;
                    break;
                }
                r = mid - 1;
            }
            else
            {
                // cout<<"goes to left\n";
                ans = max(ans, mid);
                l = mid + 1;
            }
        }
        cout << ans + 1 << "\n";
    }

    return 0;
}