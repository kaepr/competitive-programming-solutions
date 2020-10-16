#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int MAXN = 100005;
int a[MAXN], b[MAXN], s[MAXN];
int n, t;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    s[1] = a[1];
    for(int i=2; i<=n; i++)
        s[i] = s[i-1] + a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > t)
            continue;

        int l = i, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            mid++;
            if (s[mid] - s[i - 1] <= t)
                l = mid;
            else
            {
                r = mid - 1;
            }
        }
        ans = max(l - i + 1, ans);
    }
    cout << ans << "\n";

    return 0;
}