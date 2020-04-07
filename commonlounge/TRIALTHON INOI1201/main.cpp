#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int a[n],b[n],c[n],d[n],e[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        d[i] = b[i] + c[i];
    }
    
    return 0;
}