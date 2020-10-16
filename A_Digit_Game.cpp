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
    string s;
    cin >> s;
    if (n % 2 == 0)
    {
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            int num = s[i] - '0';
            int pos = i + 1;
            if (num % 2 == 0 && pos % 2 == 0)
            {
                check = true;
            }
        }
        if (check)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }
    else
    {
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            int num = s[i] - '0';
            int pos = i + 1;
            if (num % 2 != 0 && pos % 2 != 0)
            {
                check = true;
            }
        }
        if (check)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
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