#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long a[n],dp[n];
    for(int i=0;i<n;i++) scanf("%ld",&a[i]);
    if(n<=2){
        printf("0");
        return 0;
    }
    dp[0]=a[0]; dp[1]=a[1];
    dp[2] = a[2];
    for(int i=3;i<n;i++){
        dp[i] = min(dp[i-1],min(dp[i-2],dp[i-3]))+a[i];
    }
    printf("%ld",min(dp[n-1],min(dp[n-2],dp[n-3])));
	return 0;
}
