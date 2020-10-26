#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1e9 + 7;

#define pb push_back
#define f first
#define s second
#define mp make_pair

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int n, m;

void solve()
{
    // int n, m;
    cin >> n >> m;
    int rowFirst[n][m];
    int columnFirst[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rowFirst[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> columnFirst[i][j];
        }
    }

    int ans[n][m];


    int firstElm;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[rowFirst[i][0]]++;
    }

    for(int i=0; i<m; i++){
        mp[columnFirst[i][0]]++;
    }

    for(auto x : mp){
        if(x.second == 2){
            firstElm = x.first;
            break;
        }
    }



    int yes[m];
    for (int i = 0; i < n; i++)
    {
        if (rowFirst[i][0] == firstElm)
        {
            for (int j = 0; j < m; j++)
            {
                yes[j] = rowFirst[i][j];
            }
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << yes[i] << " ";
    // }

    int ans2[m][n];

    for (int i = 0; i < m; i++)
    {
        int toFind = yes[i];
        for (int j = 0; j < m; j++)
        {
            if (toFind == columnFirst[j][0])
            {
                for (int k = 0; k < n; k++)
                {
                    ans2[i][k] = columnFirst[j][k];
                }
            }
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<ans2[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ans[i][j] = ans2[j][i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    // cout << "new case\n";
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