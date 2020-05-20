#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    int total = 0;
    int ptr = 0;
    int curr_sum = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (p[i] + p[j] > x)
            j--;
        else
        {
            i++;
            j--;
        }
        total++;
    }
    cout << total;
    return 0;
}