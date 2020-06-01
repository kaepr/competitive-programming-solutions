#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a[i] = {v, i};
    }
    sort(a.begin(), a.end());
    for (int i = 0, j = n - 1; i < j;)
    {
        if (a[i].F + a[j].F == x)
        {
            cout << a[i].S + 1 << " " << a[j].S + 1 << '\n';
            return 0;
        }
        if (a[i].F + a[j].F < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}