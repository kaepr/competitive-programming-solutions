#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    sort(a.begin(), a.end());
    
    int q;
    cin>>q;
    while(q>0){
        int x;
        cin>>x;
        auto it = upper_bound(a.begin(), a.end(), x);
        cout<<it - a.begin()<<"\n";
        q--;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t = 1;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}