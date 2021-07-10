#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define f first
#define s second
#define mp make_pair

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
    int a = 0, b = 0;
    bool flag = false;
    int v = 0, il = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'V')
        {
            a++;
        }
        else if (s[i] == 'I')
        {
            b++;
        }

        if (a == 20 && b == 20)
        {
            flag = true;
        }

        if (!flag)
        {
            if (a == 21)
            {
                v++;
                a = 0, b = 0;
            }
            else if (b == 21)
            {
                il++;
                a = 0, b = 0;
            }
        }
        else if (flag)
        {
            if (a - b == 2)
            {
                v++;
                a = 0, b = 0;
                flag = false;
            }
            else if (b - a == 2)
            {
                il++;
                a = 0, b = 0;
                flag = false;
            }
        }

        // else if (a >= 20 && b >= 20)
        // {
        //     if (a - b >= 2)
        //     {
        //         v++;
        //         a = 0, b = 0;
        //     }
        //     else
        //     {
        //         il++;
        //         a = 0, b = 0;
        //     }
        // }
    }
    if (v > il)
    {
        cout << "Vaibhav\n";
    }
    else
    {
        cout << "Illisha\n";
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