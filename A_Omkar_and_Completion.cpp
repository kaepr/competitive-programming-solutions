#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        a[i] = 1;
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
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