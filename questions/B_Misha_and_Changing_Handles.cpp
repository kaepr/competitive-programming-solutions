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

    int i, q;
    cin >> q;
    vector<pair<string, string>> v;
    string x, y;
    while (q > 0)
    {
        cin >> x >> y;
        cout << x << " " << y << "\n";
        for (i = 0; i < v.size(); i++)
        {
            if (v[i].second == x)
            {
                v[i].second = y;
                break;
            }
        }
        if (i == v.size())
            v.push_back(make_pair(x, y));
        

        q--;
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}