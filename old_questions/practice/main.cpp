#include <stdio.h>

void func(int n){
    printf("\nhi\n");
}

int main(){
    int a=4;
    func(--a);
    printf("\n%d\n",a);
}