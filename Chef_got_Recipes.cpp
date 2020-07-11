#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll f[32];
    ll n;
    string st;
    cin >> n;
    for(ll i=0; i<32; i++)
        f[i] = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> st;
        ll mask = 0;
        for (char ch : st)
        {
            if (ch == 'a')
                mask = mask | (1 << 0);
            if (ch == 'e')
                mask = mask | (1 << 1);
            if (ch == 'i')
                mask = mask | (1 << 2);
            if (ch == 'o')
                mask = mask | (1 << 3);
            if (ch == 'u')
                mask = mask | (1 << 4);
        }
        f[mask]++;
    }

    ll res = 0;
    for(ll i=1; i<32; i++){
        for(ll j=i+1; j<32; j++){
            if((i|j) == 31){
                res = res + f[i]*f[j];
            }
        }
    }
    res += (f[31]*(f[31] - 1))/2;
    cout<<res<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}