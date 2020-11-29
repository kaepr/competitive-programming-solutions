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
    vector<pair<int, int>> dur;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dur.pb(mp(x, i + 1));
    }
    ll L, B, k, V;
    cin >> L >> B >> V >> k;
    ll len = 2 * (L + B);
    len = len * k;
    ll time = len / V;
    sort(dur.begin(), dur.end());

    vi ans;
    int totalTime = 0;
    for (auto x : dur)
    {
        totalTime += x.first;
        if (totalTime <= time)
        {
            ans.pb(x.second);
        }
        else
        {
            break;
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
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