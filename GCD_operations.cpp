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
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    bool isSame = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            isSame = false;
            break;
        }
    }

    if (isSame)
    {
        cout << "YES\n";
        return;
    }

    // if (n % 2 != 0)
    // {
    //     if (b[n - 1] % 2 == 0)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    // if (n % 2 == 0)
    // {
    //     if (b[n - 1] % 2 != 0 && b[n - 1] != 1)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        int num = i + 1;
        // cout << "b[i] is " << b[i] << "\n";
        // cout << num << "\n";
        if (num % b[i] == 0)
        {
            //continue
        }
        else
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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