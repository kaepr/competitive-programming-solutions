#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x,y,n;
    cin>>x>>y>>n;
    if(n - n%x + y <= n){
        cout<<n - n%x + y<<"\n";
    }else{
        cout<<n - n%x - (x - y)<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}