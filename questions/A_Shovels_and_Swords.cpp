#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a,b;
    cin>>a>>b;

    if(a > b){
        if(2*b < a){
            cout<<b<<"\n";
        }else{
            cout<<(a+b)/3<<"\n";
        }
    }else if(b > a){
        if(2*a < b){
            cout<<a<<"\n";
        }else{
            cout<<(a+b)/3<<"\n";
        }
    }else{
        cout<<(a+b)/3<<"\n";
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}