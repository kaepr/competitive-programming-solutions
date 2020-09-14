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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    
    int count1 = 0;
    int count2 = 0;
  
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count1++;
        }
        else if (a[i] == 0)
        {
            count2++;
        }
    }

    if (count1 == n)
    {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
    }
    else if (count2 == n)
    {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << 0 << " ";
        }
    }
    else if (count1 == count2)
    {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; i++)
            cout << 0 << " ";
    }
    else if (count1 > count2)
    {
        if (count1 % 2 == 0)
        {
            cout << count1 << "\n";
            for (int i = 0; i < count1; i++)
                cout << 1 << " ";
        }
        else
        {

            cout << count1 - 1 << "\n";
            for (int i = 0; i < count1 - 1; i++)
                cout << 1 << " ";
        }
    }
    else
    {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; i++)
            cout << 0 << " ";
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