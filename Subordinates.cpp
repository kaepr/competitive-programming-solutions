#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[200005];

void solve(int src, int par, vector<int>& ans){
    int subs = 0;
    for(int child : adj[src]){
        if(child!=par){
            solve(child, src, ans);
            subs += (1 + ans[child]);

        }
    }
    ans[src] = subs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> ans(n+1);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    solve(1,0,ans);
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }

       
    return 0;
}