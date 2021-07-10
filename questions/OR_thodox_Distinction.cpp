#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    set<int> s;
    int f=1;
    for(int i=0; i<n; i++){
        if(s.find(a[i])!=s.end())
            f = 0;
        else
            s.insert(a[i]);
    }

    int b[n];
    b[0] = a[0];
    for(int i=1; i<n; i++){
        
    }
    
    cout<<b[n-1]<<"\n";

    if(b[n-1] == 0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
        
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