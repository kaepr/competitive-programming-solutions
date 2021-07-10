#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5;

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

int myPow(int x, string s, int mod)
{
    x %= mod;
    int res = 1;
    int now = x;
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        res = (res * powmod(now, s[i] - '0', mod)) % mod;
        now = powmod(now, 10, mod);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    

    string s;
    cin >> s;

    int res = myPow(1, s, mod) + myPow(2, s, mod) + myPow(3, s, mod) + myPow(4, s, mod);
    res %= mod;
    cout << res << "\n";

    return 0;
}