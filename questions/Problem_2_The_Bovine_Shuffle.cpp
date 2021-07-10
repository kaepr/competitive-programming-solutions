#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a[n+1];
    int order[n+1];
    int org[n+1];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    
    for(int i=1; i<=n; i++)
        cin>>order[i];
    
    for(int j=0; j<3; j++){
        for(int i=1; i<=n; i++)
            org[i] = order[a[i]];
        for(int i=1; i<=n; i++)
            order[i] = org[i];
    }
    for(int i=1; i<=n; i++)
        cout<<order[i]<<"\n";



    return 0;
}