#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll sumAP(ll start, ll end){
    ll num = end - start + 1;
    if(num%2==0){
        return (((num/2)%mod) * ((start + end) % mod)) % mod;
    }else{
        return ((num % mod) * (((start + end)/2) % mod)) % mod;
    }
}

int main(){
    ll n;
    cin>>n;
    ll sum = 0;
    ll i;
    for(i =1; i*i <=n; i++){
        sum += ((n/i) * i);
        sum%=mod;
    }

    ll marker = i;

    for(ll occur = 1; occur*occur <=n; ++occur){
        sum = sum + (occur * (sumAP(max(n/(occur + 1) + 1, marker), n/occur))) % mod;
        sum%=mod;
    }
    cout<<sum;
    return 0;
}