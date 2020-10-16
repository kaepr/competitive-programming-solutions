#include <bits/stdc++.h>
using namespace std;
using ull = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    ull n;
    cin >> n;

    ull a[32];
    ull binaryGreatest = 1;

    ull totalSquaresRequired = 0;
    ull currentNminusOne = 0;
    int ansCnt = 0;
    for (ull i = 0; i <= 32; i++)
    {
        binaryGreatest = 1 << i;

        currentNminusOne = currentNminusOne | binaryGreatest;

        ull toAdd = currentNminusOne * (currentNminusOne + 1) / 2;
        totalSquaresRequired += toAdd;

        if (totalSquaresRequired > n)
        {
            break;
        }
        ansCnt++;
    }

    cout << ansCnt << "\n";
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}