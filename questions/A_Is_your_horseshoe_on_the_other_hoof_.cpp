#include <bits/stdc++.h>
using namespace std;
int main(){
    int n[4];
    for(int i=0; i<4; i++)
        cin>>n[i];
    
    int d=1;

    sort(n,n+4);

    for(int i=1; i<4; i++)
        if(n[i] != n[i-1])
            d++;

    cout<<4-d;
    return 0;
}