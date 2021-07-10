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
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> ans;
    while (n > 0)
    {
        int newNum = n;
        int diff = 0;
        int ptr = 0;
        while (newNum > 0)
        {
            int last = newNum % 10;
            if (last >= 1)
            {
                diff += 1 * pow(10, ptr);
            }
            else
            {
                diff += 0 * pow(10, ptr);
            }
            ptr++;
            newNum /= 10;
        }
        // cout << "n right now is " << n << " and difference is " << diff << "\n";
        cnt++;
        ans.push_back(diff);
        n -= diff;
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
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

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}