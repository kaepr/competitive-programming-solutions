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
    ll cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        ll k;
        for (ll j = i; j <= n; j++)
        {
            k = i*i + j*j;
            ll m = sqrt(k);
            if(m*m == k && m<=n)
                cnt++;
        }
    }

    cout << cnt<< "\n";

    return 0;
}
