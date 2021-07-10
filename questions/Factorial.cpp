#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt = 0;
        while (n >= 5)
        {
            n /= 5;
            cnt += n;
        }
        cout << cnt << "\n";
    }
    return 0;
}
