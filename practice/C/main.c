#include <stdio.h>

int foo(int x,int n){
    int val=1;
    if(n>0){
        if(n%2==1){
            val=val*x;
        }
        val=val*(foo(x,n-1));
    }
    return val;
}


int main(){
    int ans;
    ans = foo(4,3);
    printf("%d",ans);
    return 0;
}