#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

class MyMultiSet {
  private:
    multiset<ll> st1;
    multiset<ll> st2;
    ll k;
    ll sum;

  public:
    MyMultiSet(ll k) {
        this->k = k;
        this->sum = 0;
    }

    void insert(ll x) {
        if (st1.size() < k) {
            st1.insert(x);
            sum += x;
            return;
        }

        auto it = st1.begin();
        if (x > *it) {
            ll val = *it;
            st1.erase(it);
            sum -= val;
            sum += x;
            st2.insert(val);
            st1.insert(x);
        } else {
            st2.insert(x);
        }
    }

    void remove(ll x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            ll val = *it;
            sum -= val;
            st1.erase(it);

            auto it = st2.rbegin();
            if (!st2.empty()) {
                ll val = *(st2.rbegin());
                st2.erase(st2.find(val));
                sum += val;
                st1.insert(val);
            }

            return;
        }

        it = st2.find(x);
        if (it != st2.end()) {
            st2.erase(it);
        }
    }

    ll top_k_sum() { return this->sum; }
};

void solve() {
    ll q, k;
    cin >> q >> k;

    auto ms = MyMultiSet(k);

    while (q) {

        ll choice;
        cin >> choice;

        if (choice == 1) {
            ll x;
            cin >> x;
            ms.insert(x);
        } else if (choice == 2) {
            ll x;
            cin >> x;
            ms.remove(x);
        } else {
            char ignore;
            cin >> ignore;
            cout << ms.top_k_sum() << "\n";
        }

        q--;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
