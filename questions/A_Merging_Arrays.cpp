#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define PB push_back

int main()
{

    int n, m;
    vi a, b, c;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.PB(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.PB(x);
    }

    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    // for (auto x : b)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int a_ptr = 0, b_ptr = 0;

    while (a_ptr < n && b_ptr < m)
    {
        if (a[a_ptr] <= b[b_ptr])
        {
            c.PB(a[a_ptr]);
            a_ptr++;
        }
        else
        {
            c.PB(b[b_ptr]);
            b_ptr++;
        }
    }

    if (a_ptr == n)
    {
        for (int i = b_ptr; i < m; i++)
        {
            c.PB(b[i]);
        }
    }
    else if (b_ptr == m)
    {
        for (int i = a_ptr; i < n; i++)
        {
            c.PB(a[i]);
        }
    }

    for (auto x : c)
    {
        cout << x << " ";
    }

    return 0;
}