#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int b=0;
    int flag=0;
    for(int i=0; i<=x; i++){
        b = x - i;
        if(2*i + 4*b == y){
            flag=1;
        }
    }

    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}