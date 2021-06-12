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

ll rightAndBack(ll rem_moves, vector<ll> v, ll curr_sum, ll z, ll pos) {
    ll curr_rem = rem_moves;
    bool f = true;
    ll temp_sum = curr_sum;
    ll temp_left = z;
    while (true) {
        // trace(curr_rem, temp_left);
        if (f) {
            // go forward
            if (curr_rem > 0) {
                temp_sum += v[pos + 1];
                curr_rem--;
                f = false;
            }
            else {
                break;
            }

        }
        else {
            // go backward
            if (temp_left > 0) {
                temp_left--;
                temp_sum += v[pos];
                f = true;
            }
            else {
                break;
            }

        }
    }

    return temp_sum;
}

ll leftAndBack(ll rem_moves, vector<ll> v, ll curr_sum, ll z, ll pos) {
    ll curr_rem = rem_moves;
    bool f = true;
    ll temp_sum = curr_sum;
    ll temp_left = z;

    while (true) {
        if (f) {
            // go backward
            if (temp_left > 0) {
                temp_sum += v[pos - 1];
                temp_left--;
                f = false;
            }
            else {
                break;
            }

        }
        else {
            // go backward
            if (curr_rem > 0) {
                temp_sum = v[pos];
                curr_rem--;
                f = true;
            }
            else {
                break;
            }

        }
    }

    return temp_sum;
}


void solve() {
    ll n, k, z;
    cin >> n >> k >> z;
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.PB(x);
    }

    ll sum = 0, index;
    for (ll i = 0; i < min(n - 1, k); i++) {
        ll curr = v[i] + v[i + 1];
        if (curr > sum) {
            sum = curr;
            index = i;
        }
    }

    ll pos = 0;
    ll rem_moves = k;
    ll curr_sum = 0;
    z = min(z, min(5LL, k));
    ll ans = 0;
    trace(rem_moves, z);

    trace(index);

    for (ll i = 0; i < min(n, rem_moves); i++) {
        curr_sum += v[i];

        ll curr_rem = rem_moves;
        bool f = true;
        ll temp_sum = curr_sum;
        ll temp_left = z;

        if (i == index) {
            trace(curr_sum, curr_rem);
            while (true) {
                if (f) {
                    // go forward
                    if (curr_rem > 0) {
                        temp_sum += v[pos + 1];
                        curr_rem--;
                        f = false;
                    }
                    else {
                        break;
                    }

                }
                else {
                    if (temp_left > 0 && curr_rem > 0) {
                        temp_left--;
                        temp_sum += v[pos];
                        f = true;
                    }
                    else {
                        break;
                    }

                }
            }
        }

        trace(curr_sum);

        curr_sum = temp_sum;
        rem_moves = curr_rem;
        pos++;
    }

    cout << curr_sum << "\n";
    // cout << "NEW\n";

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

// if (i == 0) {
//     ll val1 = rightAndBack(rem_moves, v, curr_sum, z, pos);
//     ans = max(ans, val1);
// }
// else if (i == n - 1) {
//     ll val2 = leftAndBack(rem_moves, v, curr_sum, z, pos);
//     ans = max(ans, val2);
// }
// else {
//     ll val1 = rightAndBack(rem_moves, v, curr_sum, z, pos);
//     ll val2 = leftAndBack(rem_moves, v, curr_sum, z, pos);
//     val1 = max(val1, val2);
//     ans = max(ans, val1);
// }