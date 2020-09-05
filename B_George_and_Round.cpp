#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int best = n;
    if (best > m)
        best = m;

    for (int i = best; i >= 0; i--)
    {
        bool ok = true;
        for (int j = 0; j < i; j++)
            if (a[j] > b[m - i + j])
                ok = false;
        if (ok)
        {
            printf("%d\n", n - i);
            return 0;
        }
    }

    return 0;
}