#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 8 << "\n";
        }
        else if (n == 2)
        {
            cout << 98 << "\n";
        }
        else if (n == 3)
        {
            cout << 998 << "\n";
        }
        else
        {
            if (n % 4 == 0)
            {
                int cnt = n / 4;
                for (int i = 0; i < n - cnt; i++)
                    cout << 9;
                for (int i = 0; i < cnt; i++)
                    cout << 8;
                cout << "\n";
            }
            else
            {
                int cnt = n / 4 + 1;
                for (int i = 0; i < n - cnt; i++)
                    cout << 9;
                for (int i = 0; i < cnt; i++)
                    cout << 8;
                cout << "\n";
            }
        }
        t--;
    }

    return 0;
}