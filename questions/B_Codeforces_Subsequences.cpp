#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin>>k;

    string s = "codeforces";

    ll freq[10];
    for(ll i=0; i<10; i++){
        freq[i] = 1;
    }
    ll num=1;
    ll ptr=0;
    while(num<k){
        num = num / freq[ptr];
        freq[ptr]++;
        num = num * freq[ptr];
        ptr = (ptr + 1)%10;
    }
    for(ll i=0; i<10; i++){
        for(ll x = 0; x < freq[i]; ++x){
            cout<<s[i];
        }
    }

    return 0;
}