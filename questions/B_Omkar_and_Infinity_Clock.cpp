#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    
    if(k > 1){
        k = 2 + k%2;
    }

    while(k--){
        ll mx = -1e9;
        for(ll i=0; i<n; i++){
            mx = max(mx, a[i]);
        }

        for(ll i=0; i<n; i++)
            a[i] = mx - a[i];
    }

    for(ll i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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