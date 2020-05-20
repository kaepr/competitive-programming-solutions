#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll temp = n / i;
        sum = sum + temp * i;
    }
    sum = sum % MOD;
    cout << sum;
    return 0;
}