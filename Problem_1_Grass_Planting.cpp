#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int adj[100005] = {0};

int main()
{
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n - 1; i++){
        int a,b;
        cin>>a>>b;
        adj[a]++;
        adj[b]++;
    }
    int ans=0;
    // for(int i=0; i<=n; i++)
    //     cout<<adj[i]<<" ";
    
    // cout<<"\n";
    for(int i=0; i<=n; i++)
        ans = max(ans, adj[i]);

    cout<<ans + 1<<"\n";

    return 0;
}