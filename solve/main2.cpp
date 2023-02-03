#include <bits/stdc++.h>
#include <utility>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;

struct Cost {
    ll left;
    ll right;
    ll idx;
};

void solve() {
    ll n, c;
    cin >> n >> c;
    vll a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vll cost(n);
    ll mn_cost = INT_MAX;
    ll mn_idx = -1;

    for (ll i = 0; i < n; i++) {
        cost[i] = i + 1 + a[i];
        if (cost[i] < mn_cost) {
            mn_cost = cost[i];
            mn_idx = i;
        }
    }

    if (mn_cost > c) {
        // cannot even take one element
        cout << 0 << "\n";
    }

    ll ans = 1;
    c -= mn_cost;

    vector<pair<ll, ll>> v(n - 1);
    ll idx = 0;
    for (ll i = 0; i < n; i++) {
        if (i != mn_idx) {
            ll cost_left = i + 1 + a[i];
            ll cost_right = (n - i) + a[i];
            v[idx] = make_pair(cost_left, cost_right);
            idx++;
        }
    }

    sort(v.begin(), v.end(), [](auto c1, auto c2) {
        vector<pair<ll, ll>> tmp;
        tmp.push_back(make_pair(c1.first, 1));
        tmp.push_back(make_pair(c1.second, 1));
        tmp.push_back(make_pair(c2.first, 2));
        tmp.push_back(make_pair(c2.second, 2));
        sort(tmp.begin(), tmp.end());

        if (tmp[0].second == 1) {
            return true;
        }
        return false;
    });
    //
    // for (auto x : v) {
    //     cout << min(x.first, x.second) << " ";
    // }
    // cout << "\n";

    ll used = 0;
    for (ll i = 0; i < n - 1; i++) {
        used += min(v[i].first, v[i].second);

        if (used > c) {
            break;
        } else {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }

    return 0;
}
