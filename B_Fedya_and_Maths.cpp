#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 5;

int powmod(int x, int n, int mod){
    x %= mod;
    int res = 1%mod;
    while(n){
        if((n&1)){
            res = (res * x) % mod;
            n--;
        }else{
            x = (x*x) % mod;
            n>>=1;
        }
    }
    return res;
}

int myPow(int x, string s, int mod){
    x%=mod;
    int res = 1%mod;
    int now = x;
    for(int i=(int)s.size() -1; i>=0; i--){
        res = (res * powmod(now, s[i] - '0', mod))%mod;
        now = powmod(now, 10, mod);
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    
      
    return 0;
}