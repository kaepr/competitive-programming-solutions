#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<int> arr[10005];
int inDeg[10005];
int outDeg[10005];
int vis[10005];
int n;

void solve()
{

    for (int i = 0; i <= n; i++)
    {
        arr[i].clear();
    }

    // for (int i = 0; i <= n; i++)
    // vis[i] = 0;

    for (int i = 0; i <= n; i++)
        outDeg[i] = 0;

    for (int i = 0; i <= n; i++)
        inDeg[i] = 0;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        // cout << "children of " << i << "\n ";
        int cnt = 0;
        for (auto x : arr[i])
        {
            // cout << x << " ";
            cnt++;
            inDeg[x]++;
        }
        // cout << "\n";
        outDeg[i] = arr[i].size();
    }
    // int cnt1 = 0;
    // // cout << "Out Degree : \n";
    // for (int i = 1; i <= n; i++)
    // {
    //     if (outDeg[i] == 0)
    //     {
    //         cnt1++;
    //     }
    //     // cout << "i : " << i << " out is : " << outDeg[i] << "\n";
    // }
    // int cnt2 = 0;
    // // cout << "In Degree : \n";
    // int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (inDeg[i] == 0)
    //     {
    //         cnt2++;
    //     }
    //     // cout << "i : " << i << " in is : " << inDeg[i] << "\n";
    // }
    cout << inDeg[1] << "\n";
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

/*




int find()
{
    int minEdges = 0;
    int totalIndegree = 0;
    int totalOutdegree = 0;

    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] == 1)
            totalIndegree++;
        if (outDeg[i] == 1)
            totalOutdegree++;
    }

    minEdges = max(n - totalIndegree, n - totalOutdegree);

    return minEdges;
}

void dfs(int i)
{
    vis[i] = 1;

    for (auto x : arr[i])
    {
        if (vis[x] == 0)
        {
            inDeg[x]++;
            dfs(x);
        }
    }
}

void solve()
{
    for (int i = 0; i <= n; i++)
        vis[i] = 0;

    for (int i = 0; i <= n; i++)
        outDeg[i] = 0;

    for (int i = 0; i <= n; i++)
        inDeg[i] = 0;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    // for(int i=1; i<=arr[i].size(); i++){
    //     cout<<
    // }

    cout<<"elements in 1\n";
    for(auto x : arr[1]){
        cout<<x<<" ";
    }
    cout<<"\n";

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        cout << "elements\n";
        int cnt = 0;
        for (auto x : arr[i])
        {
            cout << x << " ";
            cnt++;
            inDeg[x]++;
        }
        cout << "\n";
        outDeg[i] = cnt;
        // if (vis[i] == 0)
        // {
        // dfs(i);
        // }
    }
    cnt = find();

    cout << "Out Degree : \n";
    for (int i = 1; i <= n; i++)
    {
        cout << "i : " << i << " out is : " << outDeg[i] << "\n";
    }

    cout << "Int Degree : \n";
    for (int i = 1; i <= n; i++)
    {
        cout << "i : " << i << " in is : " << inDeg[i] << "\n";
    }

    cout << cnt / 2 << "\n";
}





*/