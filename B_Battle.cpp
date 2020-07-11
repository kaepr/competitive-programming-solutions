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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int f = 1;
    while (a > 0 && c > 0)
    {
        if (f)
        {
            c = c - b;
            f = 0;
        }
        else
        {
            f = 1;
            a = a - d;
        }

        //cout<<"a health is "<<a<<" c health is "<<c<<"\n";
    }
    if (a > 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}