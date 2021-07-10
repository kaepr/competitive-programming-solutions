#include <bits/stdc++.h>

using namespace std;
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n, i, flag = 0;
    cin >> n;
    int a[20] = {0};
    for (i = 1; i <= 17; i++)
    {
        a[i] = fibonacci(i);
    }
    for (i = 1; i <= n; i++)
    {
        flag = 0;
        if (i == 1 || i == 2)
        {
            cout << "O";
            flag = 1;
        }
        else
        {
            for (int j = 1; j <= 17; j++)
            {
                if (i == a[j])
                {
                    cout << "O";
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            cout << "o";
        }
    }
    cout << endl;
    return 0;
}