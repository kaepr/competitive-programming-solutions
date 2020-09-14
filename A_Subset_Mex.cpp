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

int mex(vector<int> a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (ans < a[i])
        {
            return ans;
        }
        else
        {
            ans++;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int arr[105] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }

    int ma = 0;
    for (int i = 0; i < 105; i++)
    {
        if (arr[i] == 0)
        {
            ma = i;
            break;
        }
    }

    int mb = 0;
    for (int i = 0; i < 105; i++)
    {
        if (arr[i] <= 1)
        {
            mb = i;
            break;
        }
    }

    cout << ma + mb << "\n";
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