#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int check = 1;

    for (int i = 0; i < n; i++)
    {
        int first = i % 2;
        int second = a[i] % 2;
        if (first != second)
        {
            check = 0;
        }
    }
    if (check == 1)
    {
        cout << "0\n";
    }
    else
    {
        int con = 0;
        int cen = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 != a[i] % 2)
            {
                if (a[i] % 2 != 0)
                {
                    con++;
                }
                else
                {
                    cen++;
                }
            }
        }
        int inPlace = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == a[i] % 2)
                inPlace++;
        }

        //cout<<"odd numbers not in place are "<<con<<"\n";
        //cout<<"eveb numbers not in place are "<<cen<<"\n";
        if (cen == con)
        {
            cout << con << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}