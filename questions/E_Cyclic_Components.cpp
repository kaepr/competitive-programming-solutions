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

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int vis[MAXN];
int comp_num[MAXN];
int n, m;
vector<vector<int>> comp;
int cnt = 0;
map<int, vector<int>> mp;

void dfs(int parent, int id) {
    if (vis[parent]) {
        return;
    }
    vis[parent] = 1;
    comp_num[parent] = id;
    mp[id].PB(parent);
    for (auto x : adj[parent]) {
        if (vis[x] == 0) {
            dfs(x, id);
        }
    }
}



void solve() {

    cin >> n >> m;
    while (m > 0) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
        m--;
    }

    vector<int> nodes;
    int id = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        else {
            dfs(i, id);
            nodes.PB(id);
            id++;
        }
    }

    // nodes hold atleast 1 node from every component

    int ans = 0;
    for (auto x : mp) {
        bool f = true;
        for (auto y : x.S) {
            if (adj[y].size() != 2) {
                f = false;
                break;
            }

        }
        if (f) {
            ans++;
        }
    }
    cout << ans << "\n";

}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }

    return 0;
}