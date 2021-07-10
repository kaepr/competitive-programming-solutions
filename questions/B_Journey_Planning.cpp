#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    ll b[n];
    for(ll i=0;  i<n; i++)
        cin>>b[i];

    ll ans=0;

    ll diff[n];
    for(ll i=0; i<n; i++){
        diff[i] = abs(i - b[i]);
    }

    map<ll,ll> mp;
    for(ll i=0; i<n; i++){
        mp[b[i]-i]+=b[i];
        ans = max(ans, mp[b[i] - i]);
    }

    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}