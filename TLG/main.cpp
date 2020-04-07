#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int A[n],B[n],sumA=0,sumB=0,leadA,leadB,l[n],s=0,w;
    for(int i=0;i<n;i++){
        scanf("%d%d",&A[i],&B[i]);
        sumA = sumA + A[i];
        sumB = sumB + B[i];
        if(sumA > sumB){
            leadA=sumA-sumB;
            l[i] = leadA;
        }else if(sumB  >sumA){
            leadB = sumA - sumB;
            l[i] = leadB;
        }

        if(leadA > s){
            s=leadA;
            w=1;
        }

        if(leadB  > s){
            s=leadB;
            w=2;
        }
    }
    printf("%d %d",w, s);
    return 0;
}