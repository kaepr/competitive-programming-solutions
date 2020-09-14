#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll pSum = 0;
        ll cnt = 0;
        ll minValue = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                pSum += a[i];
                continue;
            }
            if (a[i] < 0 && pSum > 0)
            {

                if (pSum - abs(a[i]) > 0)
                {
                    pSum = pSum - abs(a[i]);
                }
                else
                {
                    pSum = 0;
                }
            }
        }
        cnt += pSum;
        cout << cnt << "\n";
        t--;
    }

    return 0;
}