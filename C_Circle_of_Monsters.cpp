#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    sort(a, a+ n);
    if(n%2==1){
        cout<<a[n/2]<<" ";
    }
    for(int i=n/2 - 1; i>=0; i--){
        cout<<a[n-i-1]<<" "<<a[i]<<" ";
    }
    cout<<"\n";
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