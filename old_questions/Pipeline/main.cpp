#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main(){
    ull n,k;
    cin>>n>>k;
    if(n==1){
        cout<<0;
        return 0;
    }
    ll max = (ll) k*(k-1)/2 + 1;
    if(n>max){
        cout<<1;
    }else if(n<=k){
        cout<<1;
    }else{
        int st=0, end=k-1;
        while(st<=end){
            int mid = (st+end)/2;
            ll sum = max - (ll)mid*(mid+1)/2;
            if(n>sum)
                end = mid-1;
            else
                st = mid+1;
        }
        cout<<k-st;
    }
    return 0;
}