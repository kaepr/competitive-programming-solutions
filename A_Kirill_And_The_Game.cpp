#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    ll f=0;
    for(ll i=x; i<=y; i++){
        if(l<=i*k && i*k<=r)
            f=1;
    }

    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}