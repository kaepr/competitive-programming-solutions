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

    map<ll, ll> mp;

    ll n, sum;
    cin >> n >> sum;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll currsum = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        currsum += a[i];

        if (currsum == sum)
            ans++;

        if (mp.find(currsum - sum) != mp.end())
            ans += mp[currsum - sum];

        mp[currsum]++;
    }
    cout << ans << "\n";

    return 0;
}