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
    ll l, b;
    cin >> l >> b;
    int n;
    cin >> n;
    ll ans = 0;
    while (n > 0)
    {
        int hl, hb;
        cin >> hl >> hb;
        if (min(l, b) > min(hl, hb))
        {
            n--;
            continue;
        }
        else if (l * b > hl * hb)
        {
            n--;
            continue;
        }
        else if (l * b == hl * hb)
        {
            ans++;
            n--;
            continue;
        }

        int currSum = 0;
        //first case
        int maxLength;
        if (hl % l == 0)
        {
            maxLength = hl;
        }
        else
        {
            maxLength = (hl / l) * l;
        }

        int maxBreadth;
        if (hb % b == 0)
        {
            maxBreadth = hb;
        }
        else
        {
            maxBreadth = (hb / b) * b;
        }

        int maxArea = maxBreadth * maxLength;

        currSum = maxArea / (l * b);

        int maxLength2;
        if (hl % b == 0)
        {
            maxLength2 = hl;
        }
        else
        {
            maxLength2 = (hl / b) * b;
        }

        int maxBreadth2;
        if (hb % l == 0)
        {
            maxBreadth2 = hb;
        }
        else
        {
            maxBreadth2 = (hb / l) * l;
        }

        int maxArea2 = maxBreadth2 * maxLength2;

        int currSum2 = maxArea2 / (l * b);
        ans += max(currSum, currSum2);
        n--;
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

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}