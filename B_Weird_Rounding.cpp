#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll n,k;
    cin>>n>>k;
    int cnt=0;

    for(ll i=1; i<=k; i++){
        ll lastDigit = n%10;
            cnt++;
        
        n/=10;
    }
    cout<<cnt;
    return 0;
}