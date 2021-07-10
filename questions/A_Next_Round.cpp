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

    int cnt = 0;
    int n, k;
    cin >> n >> k;
    int a[n+1];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int base = a[k];
    //cout << "base value is " << base << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= base && a[i] > 0)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}