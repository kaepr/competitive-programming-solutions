#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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

    int n;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        
        int x;
        cin >> x;
        if(x > 0  && x <=n ){
            a[x]++;
        }
        // a[x]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (i > 0 && a[i] < 1)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << n + 1 << "\n";
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