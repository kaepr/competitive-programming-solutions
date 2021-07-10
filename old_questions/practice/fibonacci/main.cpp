#include <stdio.h>
void fibn(int n){
    int a=0,b=1,c;
    for(int i=0; i<n;i++){
        if(i<=1){
            printf("%d ",i);
        }else{
            c=a+b;
            a=b;
            b=c;
            printf("%d ",c);
        }
    }
}

int main(){
    printf("How many numbers in fibonacci series you want : ");
    int n;
    scanf("%d",&n);
    fibn(n);
    return 0;
}