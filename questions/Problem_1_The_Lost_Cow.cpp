#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    int ans = 0;
    int by = 1;
    int dir = 1;
    while (true)
    {

        if ((dir == 1 && x <= y && y <= x + by) || (dir == -1 && x - by <= y && y <= x))
        {
            // We found Bessie!
            ans += abs(y - x);
            cout << ans << endl;
            break;
        }
        else
        {
            ans += by * 2;
            by *= 2;
            dir *= -1;
        }
    }

    return 0;
}