#include <bits/stdc++.h>
using namespace std;
int minval(int arr[],int a, int b){
    int min=1000;
    for(int i=a; i<=b; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int main(){
    int t,n,ans=1,start=0,end=0;
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        int pri[n];
        for(int i=0; i<n; i++){
            scanf("%d",&pri[i]);
        }
        for(int i=1; i<n; i++){
            if(pri[i] < minval(pri,start,end)){
                ans++;
            }
            end++;
            if( (i-start) == 5){
                start++;
            }
        }
        t--;
    }
    printf("\nanswer %d",ans);
    return 0;
}
