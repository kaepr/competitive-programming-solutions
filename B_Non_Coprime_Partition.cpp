#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        int k;
        if (n % 2 == 0)
        {
            k = n / 2;
        }
        else
        {
            k = (n + 1) / 2;
        }
        cout << "1 " << k << "\n";
        cout << n - 1 << " ";
        for (int i = 1; i <= n; i++)
        {
            if (i == k)
                continue;
            cout << i << " ";
        }
        cout<<"\n";
    }

    return 0;
}