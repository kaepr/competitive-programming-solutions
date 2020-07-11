#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<n; i++)
        cin>>b[i];

    ll sa=0,sb=0;

    ll ans = 0;
    for(ll i=0; i<n; i++){
        if(a[i]==b[i] && sa==sb)
            ans += a[i];
        
        sa+=a[i];
        sb+=b[i];
    }
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}