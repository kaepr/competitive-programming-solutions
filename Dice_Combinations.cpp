#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    ll ways = 0;
    ll dp[n + 1];

    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    if(n==2){
        cout << "2"
             << "\n";
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    for (ll i = 6; i <= n; i++)
    {
        dp[i] = dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod + dp[i - 4] % mod + dp[i - 5] % mod + dp[i-6]%mod;
    }

    cout << dp[n] % (mod);

    return 0;
}