#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args &&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod) {
    int res = 1;
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

const int MOD = 1e9 + 7;

ll calc(vi arr, ll index) {

    ll sum = 0;
    for (ll i = 0; i < arr.size(); i++) {
        sum += abs(arr[i] - (arr[index] - index + i));
    }
    return sum;
}

void solve() {
    ll  n;
    cin >> n;
    string s;
    cin >> s;
    ll sheep = 0;
    for (auto x : s) {
        if (x == '*') {
            sheep++;
        }
    }

    ll empty = n - sheep;

    if (empty == 0 || empty == n || sheep == 1) {
        cout << "0\n";
        return;
    }

    vi bad_pos;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '*') {
            bad_pos.PB(i);
        }
    }

    ll bps = bad_pos.size();

    // for (auto x : bad_pos) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    ll elm1 = bps / 2;
    ll elm2 = bps / 2 + 1;
    // trace(elm1, elm2);
    // cout << calc(bad_pos, elm1) << "\n";
    ll ans = min(calc(bad_pos, elm1), calc(bad_pos, elm2));
    cout << max(ans, 0LL) << "\n";

}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }

    return 0;
}