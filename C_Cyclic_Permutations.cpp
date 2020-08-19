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

    ll res = 1, fact = 1;
    ll n;
    cin >> n;
    for (ll i = 1; i <= n - 1; i++)
    {
        res *= 2;
        fact *= i;
        fact %= mod;
        res %= mod;
    }
    fact *= n;
    fact %= mod;
    fact -= res;
    fact %= mod;
    if (fact < 0)
        fact += mod;
    cout << fact << "\n";
    return 0;
}