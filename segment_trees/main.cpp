#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using m_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
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

const ll MOD = 1e9 + 7;

// summation
struct segtree {
    vector<int> st;
    int n;

    void init(int _n) {
        this->n = _n;
        // default value set to 0
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, ending, 2 * node + 2, v);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void build(vector<int> &v) {
        build(0, v.size() - 1, 0 , v);
    }



    int query(int start, int ending, int l, int r, int node) {
        if (start > r || ending < l) {
            // change based on case
            return 0;
        }


        if (start >= l and ending <= r) {
            return st[node];
        }

        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        // change based on problem
        return q1 + q2;
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int node, int index, int value) {

    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

void solve() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    trace(v.size());

    segtree tree;
    tree.init(v.size());
    tree.build(v);
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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
