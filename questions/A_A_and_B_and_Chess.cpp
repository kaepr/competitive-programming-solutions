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

    int k, m, n1, n2;
    cin >> n1 >> n2 >> k >> m;
    vector<int> a(n1);
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    vector<int> b(n2);
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    if (a[k - 1] < b[n2 - m])
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }

    return 0;
}