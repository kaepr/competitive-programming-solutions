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

    int n, ans = 1;
    string a, b, c;
    map<string, int> mp;
    mp["polycarp"] = 1;
    cin >> n;
    while (n > 0)
    {
        cin >> a >> b >> c;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        int add = mp[c] + 1;
        if (add > ans)
        {
            ans = add;
        }
        mp[a] = add;
        n--;
    }
    cout << ans << "\n";

    return 0;
}