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
    string s;
    cin >> s;
    vector<int> pos;
    pos.push_back(0);
    for (int i = 0; i < int(s.size()); ++i)
    {
        if (s[i] == 'R')
            pos.push_back(i + 1);
    }
    pos.push_back(s.size() + 1);
    int ans = 0;
    for (int i = 0; i < int(pos.size()) - 1; ++i)
    {
        ans = max(ans, pos[i + 1] - pos[i]);
    }
    cout << ans << endl;
}

int main()
{
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