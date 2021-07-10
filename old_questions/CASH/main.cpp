#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        ll arr[n];
        ll k;
        cin >>k;
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum = sum + arr[i];
        
        ll ans = sum % k;
        cout << ans << "\n";
        t--;
    }
    return 0;
}
