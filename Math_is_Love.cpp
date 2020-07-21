#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    ll l=1, r=1e9;
    ll ans = -1;
    while(l<=r){
        ll m = l + ( r - l)/2;
        ll sum = m*(m+1)/2;
        if(sum==n){
            ans = m;
            break;
        }else if(sum > n)
            r = m - 1;
        else
            l = m + 1;
    }
    if(ans == -1){
        cout<<"NAI\n";
    }else{
        cout<<ans<<"\n";
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