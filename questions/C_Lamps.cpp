#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int b[n + 1];

    for (int i = 1; i <= k; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            int inten = a[i];
            if (inten != 0)
            {
                int coor = i;
                int low = coor - inten - 0.5;
                int high = coor + inten + 0.5;
                int illumi = 0;
                if (low < 0)
                    low = 0;

                for (int i = low; i < high; i++)
                    illumi++;

                a[i] = illumi;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}