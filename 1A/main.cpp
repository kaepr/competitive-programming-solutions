#include <iostream>

using namespace std;
using ll = long long;

int main(void)
{
    long long a, n, m, l, w;
    cin >> n >> m >> a;

    srand((unsigned)time(NULL));

    ll cnt = 0;
    for (int i = 1; i <= 100000; i++)
    {
        // cout << ((float)rand() / RAND_MAX) * 30 << endl;
        ll x = ((float)rand() / RAND_MAX) * 30;
        ll y = ((float)rand() / RAND_MAX) * 30;
        if (x > y)
        {
            if ((x - y) < 7)
            {
                cnt++;
            }
        }
        else if (y > x)
        {
            if ((y - x) < 5)
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}