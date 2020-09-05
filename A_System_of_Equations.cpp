#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i <= max(n, m); i++)
    {
        for (int j = 0; j <= max(m, n); j++)
        {
            if (i * i + j == n && j*j + i == m){
                // cout<<i<<" "<<j<<"\n";
                cnt++;
            }
              
        }
    }

    cout << cnt << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}