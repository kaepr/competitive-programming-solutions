#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        ll elm = s[i] - '0';
        elm--;
        sum += elm;
        ans += mp[sum];
        mp[sum]++;
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