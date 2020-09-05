#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());

    int low = *min_element(a, a + n);

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == a[i])
            continue;
        if (v[i] % low > 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "NO\n";
    else
        cout << "YES\n";
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