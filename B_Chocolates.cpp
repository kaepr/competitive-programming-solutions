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

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    ll sum=0;
    ll cur = 1e18;
    for(int i=n-1; i>=0; i--){
        cur = min(cur-1, (ll) a[i]);
        cur = max(0LL, cur);
        sum+=cur;
    }
    cout<<sum<<"\n";

    return 0;
}