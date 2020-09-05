#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, t;
    cin >> n >> x >> t;
    int c = n / x;
    // cout<<"c is "<<c<<"\n";
    int rem = n % x;
    // cout<<rem<<"\n";
    int ans = 0;
    if (rem > 0)
    {
        ans++;
    }

    ans += c;
    // cout<<ans<<"\n";
    cout << ans * t << "\n";

    return 0;
}