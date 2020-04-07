#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,K;
    scanf("%lld%lld",&N,&K);
    long long arr[N];
    for(long long i=0; i<N; i++){
        scanf("%lld",&arr[i]);
    }
    long long a = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+a);
    long long count=0;
    int i=0,j=1;
    while(j<N)
    {
        if(arr[j]-arr[i]>=K)
        {
            count=count+N-j;
            i++;
        }
        else
        {
            j++;
        }
    }
    printf("%lld\n",count);
    return 0;
}