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

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < (1 << 9); i++)
    {
        bool possible = 1;
        for (int j = 0; j < n; j++)
        {
            bool flag = 0;
            for (int k = 0; k < m; k++)
            {
                int c = a[j] & b[k];
                if ((c | i) == i)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                possible = 0;
                break;
            }
        }
        if (possible)
        {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}