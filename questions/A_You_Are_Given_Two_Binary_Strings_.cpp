#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    char x[100010], y[100010];
    int num1 = 0, num2 = 0;
    cin >> x >> y;
    for (int j = strlen(y) - 1; j >= 0; --j)
    {
        num1++;
        if (y[j] == '1')
            break;
    }
    for (int j = strlen(x) - num1; j >= 0; --j)
    {
        num2++;
        if (x[j] == '1')
            break;
    }
    num2 += num1;
    cout << num2 - num1 - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}