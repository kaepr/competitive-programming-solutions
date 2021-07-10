#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
    }else if(n==2){
        cout<<1<<"\n";
    }else{
        if(n%2!=0){
            cout<<1 + (n-1)/2<<"\n";
        }else{
            cout<<n/2<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}