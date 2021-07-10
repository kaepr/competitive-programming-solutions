#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x%k==0){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    cout<<"\n";
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