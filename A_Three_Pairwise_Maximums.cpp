#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    vector<int> a(3);
    for(int i=0; i<3; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    if(a[2]!=a[1]){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        cout<<a[0]<<" "<<a[0]<<" "<<a[2]<<"\n";
    }
}

int main()
{
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