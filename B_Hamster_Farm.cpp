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
    ll a[k];
    for(ll i=0; i<k; i++){
        cin>>a[i];
    }

    ll rem[k];
    for(ll i=0; i<k; i++){
        rem[i] = n % a[i];
    }    

    ll m=rem[0];
    ll pos=0;
    for(int i=1; i<k; i++){
        if(rem[i] < m){
            m = rem[i];
            pos = i;
        }
    }
    cout<<pos+1<<" "<<n/a[pos]<<"\n";
    
    return 0;
}