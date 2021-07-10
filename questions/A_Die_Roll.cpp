#include <bits/stdc++.h>
using namespace std;
void simple(int& a, int& b){
    int GCD = __gcd(a,b);
    a /= GCD;
    b /= GCD;
}

int main(){
    int Y,W;
    cin>>Y>>W;
    int D = 6 - max(Y,W) + 1;
    int s=6;
    simple(D, s);
    cout<<D<<"/"<<s;    
    return 0;
}