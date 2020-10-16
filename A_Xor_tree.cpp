#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int MAXN = 200005;
vector<int> adj[MAXN];
int vis[MAXN],a[MAXN], b[MAXN];
vector<int> ans;

void dfs(int x, int curr, int par){
    vis[x] = 1;
    if(a[x] != b[x] && curr == 0){
        ans.push_back(x);
        curr = 1;
    }
    if(a[x] == b[x] && curr == 1){
        ans.push_back(x);
        curr = 0;
    }
    for(int i=0; i<adj[x].size(); i++){
        if(!vis[adj[x][i]]){
            dfs(adj[x][i], par, curr);
        }
    }
}


int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for( int i = 1 ; i <= n ; i++ )
        cin >> a[i] ;
    for( int i = 1 ; i <= n ; i++ )
        cin >> b[i] ;

    dfs(1,0,0);
    cout<<(int)ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    

    return 0;
}