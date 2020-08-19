#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<int> adj[100005];
int n,m,a,b;

void solve()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int star_flag = false;
    int cnt_one_deg = 0;
    int cnt_two_deg = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == n-1){
            star_flag = true;
        }else if(adj[i].size() == 2){
            cnt_two_deg++;
        }else if(adj[i].size() == 1){
            cnt_one_deg++;
        }
    }
    if(star_flag && cnt_one_deg == n-1 && cnt_two_deg == 0){
        cout<<"star topology\n";
    }else if(cnt_two_deg == n && star_flag == false && cnt_one_deg == 0){
        cout<<"ring topology\n";
    }else if(cnt_one_deg == 2 && star_flag == false && cnt_two_deg == n-2){
        cout<<"bus topology\n";
    }else{
        cout<<"unknown topology\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}