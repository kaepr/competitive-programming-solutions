#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin>>n>>k;
    ll count = 0,sum=0;
    ll z = pow(2,n) - 1;
    ll x = 1;
    if(k%2==1){
        cout<<1<<"\n";
        return 0;
    }
    while(1){
        ll y = (x + z)/2;
        if(k==y){
            cout<<n<<"\n";
            return 0;
        }else if(y > k){
            z = y - 1;
        }else{
            x = y+1;
        }
        n--;
    }

    return 0;
}