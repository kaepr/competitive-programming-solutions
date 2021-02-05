#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int sequence(int x, int n, int a[])
{
    int deg = 0;

    for (int i = 0; i < n; i++)
    {
        if (x & 1)
            deg += a[i];
        else
            deg -= a[i];

        x >>= 1;
    }

    return deg;
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

    int tot = (1 << n);
    bool f = false;
    for (int i = 0; i < tot; i++)
    {
        int degree = sequence(i, n, a);
        if(abs(degree) % 360 == 0 || degree == 0)
            f = true;
    }
    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    

    return 0;
}
