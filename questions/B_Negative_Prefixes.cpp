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
    vector<pair<int, int>> vi;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vi.push_back(make_pair(x, 0));
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vi[i].second = x;
    }

    vector<int> unlock;
    vector<pair<int, int>> lock;
    for (int i = 0; i < n; i++)
    {
        if (vi[i].second == 0)
            unlock.push_back(vi[i].first);
    }

    sort(unlock.begin(), unlock.end());
    reverse(unlock.begin(), unlock.end());

    int ptr = 0;

    for (int i = 0; i < n; i++)
    {
        if (vi[i].second == 1)
        {
            cout << vi[i].first << " ";
        }
        else
        {
            cout << unlock[ptr] << " ";
            ptr++;
        }
    }

    cout << "\n";
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