#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0)
        {
            int j = x / i;
            if (j <= n)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}