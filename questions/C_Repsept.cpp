#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    ll pattern = 7;
    ll cnt = 1;
    ll ans = -1;
    for(ll i=1; i<=n; i++){
        if(pattern % n == 0){
            ans = cnt;
            break;
        }else{
            pattern = (pattern*10 + 7)%n;
            cnt++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}