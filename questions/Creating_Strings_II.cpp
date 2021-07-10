#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_char = 26;
int fact[1000001];
const ll mod  = 1e9 + 7;


ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % mod;
 
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}

void compute()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}


ll C(ll n, ll k)
{
    if (k > n)
        return 0;
 
    ll res = fact[n];


 
    res = (res * power(fact[k], mod - 2)) % mod;
    res = (res * power(fact[n - k], mod - 2)) % mod;
    return res;
}


int main(){
    compute();
    string s;
    cin>>s;
    int n = s.length();


    int freq[max_char];
    memset(freq, 0 , sizeof(freq));


    for(int i=0; i<n; i++)
        if(s[i] >= 'a')
            freq[s[i] - 'a']++;


    //for(int i=0; i<n; i++)
    //    cout<<freq[i]<<" ";

    //cout<<"\n";


    ll res = fact[n];

    for(int i=0; i<max_char; i++){
        res = (res * power(fact[freq[i]], mod - 2)) % mod;
    }
    
    cout<<res;


    // int denom=1;
    // for(int i=0; i<max_char; i++){
    //     denom = denom * fact[freq[i]];
    //     denom %= mod;
    // }
       

    // int ans = fact[n]/denom;
    
    // cout<<ans;
    return 0;
}