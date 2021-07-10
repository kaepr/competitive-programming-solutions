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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < k; i++)
    {
        if (s[i] == '?')
        {
            for (int j = i + k; j < n; j += k)
            {
                if (s[j] != '?')
                {
                    s[i] = s[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (s[i] != '?')
        {
            for (int j = i + k; j < n; j += k)
            {
                if (s[j] == '?')
                {
                    s[j] = s[i];
                }
                else if (s[j] != s[i])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    int one = 0, zero = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '1')
            one++;
        if (s[i] == '0')
            zero++;
    }

    if (one <= k / 2 && zero <= k / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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