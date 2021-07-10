#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,r,ans;
    cin>>k>>r;
    int flag=1;
    int num=1;
    int sh=0;
    while(num<11){
        if(((k*num)%10 == r) || ((k*num)%10 == 0)){
            flag=0;
            ans = num;
            break;
        }
        num++;
    }

    cout<<ans;
    return 0;
}