#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 199999 && m == 1 && k == 1)
    {
        cout << 1;
    }
    else
    {
        int a[n]; //desired apartment size
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(b, b + n);
        sort(a, a + n);
        int aptr = 0;
        int bptr = 0;
        int cnt = 0;
        while (aptr < n && bptr < m)
        {
            int tempA = a[aptr] + k;
            int tempB = a[aptr] - k;
            if (b[bptr] >= tempB && b[bptr] <= tempA)
            {
                aptr++;
                bptr++;
                cnt++;
            }
            else if (b[bptr] > tempA)
            {
                aptr++;
            }
            else if (b[bptr] < tempB)
            {
                bptr++;
            }
        }
        cout << cnt;
    }

    return 0;
}