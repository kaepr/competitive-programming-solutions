#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin>>n>>k;
    if(n>=k){
        cout<<(k-1)/2<<"\n";
    }else if(n*2 > k){
        cout<<(n - k/2)<<"\n";
    }else{
        cout<<"0\n";
    }

    return 0;
}