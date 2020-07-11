#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve(){
    ull a,b,n,m;
    cin>>a>>b>>n>>m;
    ull v = a;
    ull c = b;
    if( v + c < n + m)
        cout<<"No\n";
    else if(min(v,c) < m)
        cout<<"No\n";
    else{
        cout<<"Yes\n";
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