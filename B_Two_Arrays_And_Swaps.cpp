#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    

    sort(a,a+n);
    sort(b,b+n, greater<>());
    int ans=0;

    for(int i=0; i<k; i++){
        if(b[i] > a[i])
            swap(a[i],b[i]);
    }
    for(int i=0; i<n; i++)
        ans+=a[i];

    cout<<ans<<"\n";

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