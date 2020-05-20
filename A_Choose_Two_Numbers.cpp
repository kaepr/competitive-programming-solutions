#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = a[i] + b[j];
            if (flag != 1)
            {
                if (search(a, 0, n - 1, t) == -1 && search(b, 0, m - 1, t) == -1)
                {
                    cout << a[i] << " " << b[j];
                    flag = 1;
                }
            }
        }
    }

    return 0;
}