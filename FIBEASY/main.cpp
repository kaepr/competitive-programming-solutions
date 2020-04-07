#include <bits/stdc++.h>
#include <array>
using namespace std;

/*
int remove_odd(int A[],int N){
    int answ;
    int B[N];
    
    for(int i=0;i<N;i++){
        if(sizeof(B)/sizeof(*B)==1){
            break;
        }
        for(int j=0; j<N;j=j+2){
                B[i] = A[j];
        }
    }
    if(sizeof(B)/sizeof(*B)==1){
        return B[0];
    }
    return answ=remove_odd(B,sizeof(B)/sizeof(*B));
}
*/

int main(){
    int t,n,a=0,b=1,c;
    scanf("%d",&n);
    int F[n];
    for(int i=0; i<n; i++){
        if(i<=1){
            c=i;    
        }else{
            c=a+b;
            a=b;
            b=c;
        }
        F[i] = c%10;
    }
    //int ans = remove_odd(F,n);
    for(int i=0;i<n;i++){
        printf("%d ",F[i]);
    }
    int answ=sizeof(F)/sizeof(*F);
    printf("\n%d ",answ);
    int B[n/2];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j=j+2){
            B[i]=F[j];
        }
    }
    int answwe=sizeof(B)/sizeof(*B);
    printf("\n%d ",answwe);

    return 0;
}