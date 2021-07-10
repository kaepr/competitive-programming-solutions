#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int k=0;
    while(k<n && a[k]==1)
        k++;
    
    if(k==n){
        if(k%2==0)
            cout<<"Second\n";
        else
            cout<<"First\n";
    }else{
        if(k%2==0)
            cout<<"First\n";
        else
            cout<<"Second\n";
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