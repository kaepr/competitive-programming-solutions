#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string b;
    cin >> b;
    int n = b.length();
    if (n == 2)
    {
        cout << b << "\n";
        return;
    }

    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            cout << b[i];
        }
        cout<<b[n-1];
        cout<<"\n";
    }else{
        int till = n-1;
        for (int i = 0; i < till; i += 2)
        {
            cout << b[i];
        }
        cout<<b[n-1];
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}