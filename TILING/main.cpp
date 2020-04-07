#include <bits/stdc++.h>
using namespace std;

int noofways(int n){
    if(n==1)    return 1;
    if(n==2)    return 2;
    
    return noofways(n-1) + noofways(n-2);
}

int main(){

    return 0;
}
