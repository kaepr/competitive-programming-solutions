#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int a,b;
    cin>>a>>b;
    if(a*2 > b){
        cout<<"-1 -1\n";
    }else{
        cout<<a<<" "<<2*a<<"\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}