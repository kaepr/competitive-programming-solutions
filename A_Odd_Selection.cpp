#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int flag = 0;
        int o = 0;
        int e = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }

        int f = 0;
        for (int i = 1; i <= o && i <= x; i += 2)
        {
            if (e + i >= x)
                f = 1;
        }
        if (f == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }

        t--;
    }
    return 0;
}

/*
for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }

        if(o==0){
            cout << "No\n";
        }else if(o==x){
            cout << "Yes\n";
        }
*/