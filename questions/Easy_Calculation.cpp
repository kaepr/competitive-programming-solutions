#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        double a, b, c;
        cin >> a >> b >> c;
        double l = 0, r = c;
        double ans = 0;
        // cout<<ans<<"\n";

        for (int i = 0; i < 50; i++)
        {
            double m = l + (r - l) / 2.0;
            // cout << m << "\n";
            double val = a * m + b * sin(m);
            // cout<<val<<"\n";
            if (val >= c)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
                ans = m;
            }
        }
        cout <<setprecision(8) <<ans << "\n";

        t--;
    }

    return 0;
}