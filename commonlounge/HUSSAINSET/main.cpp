#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    vector<long long> arr;
    for(int i=0; i<n; i++){
        long long num;
        scanf("%lld",&num);
        arr.push_back(num);
    }
    long long que[m];
    for(int i=0; i<m; i++){
        long long num1;
        scanf("%lld",&num1);
        que[i] = num1;
    }
    sort(arr.begin(), arr.end());
    
    return 0;
}