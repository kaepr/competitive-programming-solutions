#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

//m +r - l , m - r + l
/*

l = 4, r = 6
r- l = 6 - 4 = 2;
l - r =4 - 6 = -2

*/
void solve()
{
    ll l, r, m, a, b, c;
    cin >> l >> r >> m;
    int f = 0;
    for (ll i = l; i <= r; i++)
    {
        a = i;
        if (a - m % a <= r - l)
            c = r, b = r - (a - m % a);
        else
            b = r, c = r - m % a;

        if (b <= r && b >= l && c <= r && c >= l)
            break;
    }
    cout << a << " " << b << " " << c << "\n";
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