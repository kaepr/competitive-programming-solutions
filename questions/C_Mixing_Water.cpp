#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        double a, b, c;

        cin >> a >> b >> c;

        double avg = (a + b) / 2;
        if (a == c)
        {
            cout << 1 << endl;
            continue;
        }
        if (avg >= c)
        {
            cout << 2 << endl;
        }
        else
        {
            double ans1 = (c - b) / (1.0 * (2 * c - a - b));
            double ans2 = ceil(ans1);
            ans1 = floor(ans1);
            double f1 = (((ans1 * a) + ((ans1 - 1) * b)) * (1.0)) / ((1.0) * (ans1 + ans1 - 1));
            double f2 = (((ans2 * a) + ((ans2 - 1) * b)) * (1.0)) / ((1.0) * (ans2 + ans2 - 1));
            double d1 = ((c * 1.0) - f1);
            double d2 = ((f2 - (c * (1.0))));
            d1 = abs(d1);
            d2 = abs(d2);
            if (d1 <= d2)
            {
                cout << 2 * ans1 - 1 << endl;
            }
            else
            {
                cout << 2 * (ans2)-1 << endl;
            }
        }
    }
    return 0;
}
