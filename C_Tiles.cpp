#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll w, h;
    cin >> w >> h;
    ll a = w + h;
    ll ans = 1;
    for (ll i = 1; i <= a; i++)
    {
        ans = ans * 2;
        ans %= mod;
    }
    ans %= mod;
    cout << ans << "\n";

    return 0;
}