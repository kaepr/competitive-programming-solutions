#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> arr[100005];
int ans[100005];
void solve(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(i);
        arr[b].push_back(i);
        ans[i] = -1;
    }
    pair<int,int> mx(0,0);
    for(int i=1; i<=n; i++)
        mx = max(mx, make_pair((int) arr[i].size(),i));

    int cur = 0;
    for(int i : arr[mx.second])
        ans[i] = cur++;

    for(int i=1; i<n; i++){
        if(ans[i]==-1)
            ans[i]=cur++;
        
        cout<<ans[i]<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}