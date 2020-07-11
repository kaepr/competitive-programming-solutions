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

    int sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sum += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << sum << "\n";
    return 0;
}