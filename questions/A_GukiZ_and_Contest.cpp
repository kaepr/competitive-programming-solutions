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

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int s = 1;
        for (int j = 0; j < n; j++)
            if (a[j] > a[i])
                s++;

        cout << s;
        if (i < n - 1)
            cout << " ";
        else
        {
            cout << "\n";
        }
    }

    return 0;
}