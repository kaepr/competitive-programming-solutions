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

void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int elm1 = a[i][j];
            int elm2 = a[i][m - j - 1];
            int elm3 = a[n - i - 1][j];
            vi v;
            v.pb(elm1);
            v.pb(elm2);
            v.pb(elm3);
            sort(v.begin(), v.end());
            // cout<<"All elements : \n";
            // for(auto x : v){
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            int mid = v[1];
            ans += (v[1] - v[0]) + (v[2] - v[1]);
            a[i][j] = mid;
            a[i][m - j - 1] = mid;
            a[n - i - 1][j] = mid;
        }
    }
    cout << ans << "\n";
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