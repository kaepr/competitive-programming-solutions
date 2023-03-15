#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define first fst
#define second snd

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

/*

4 4
..TT..
K.....
K...K.

Find the shortest distance b/w any knight and target

*/

int n, m;
vector<string> arr;

vector<int> dx = {2, 1, 1, 2, -2, -1, -1, -2};
vector<int> dy = {1, 2, -2, -1, -1, -2, 2, 1};

bool check(int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; }

using state = pair<int, int>;

const int INF = 1e9;

vector<vector<int>> dis;
vector<vector<state>> par;

void bfs(vector<state>& sources) {
    queue<state> q;

    for (auto source : sources) {
        dis[source.first][source.second] = 0;
        par[source.first][source.second] = {-1, -1};
        q.push(source);
    }

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        int cur_dist = dis[cur.first][cur.second];

        for (int k = 0; k < 8; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (check(nx, ny) and dis[nx][ny] > cur_dist + 1) {
                dis[nx][ny] = cur_dist + 1;
                par[nx][ny] = cur;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<state> knights, targets;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'K') {
                knights.push_back({i, j});
            }

            if (arr[i][j] == 'T') {
                targets.push_back({i, j});
            }
        }
    }

    dis.assign(n, vector<int>(m, INF));
    par.assign(n, vector<state>(m, make_pair(-1, -1)));

    bfs(knights);

    int min_dis = INF;
    state min_dis_target = {-1, -1};

    for (auto target : targets) {
        int x = target.first;
        int y = target.second;
        if (dis[x][y] < min_dis) {
            min_dis = min(min_dis, dis[x][y]);
            min_dis_target = target;
        }
    }

    vector<state> target_path;
    state end = {-1, -1};

    while (min_dis_target != end) {
        target_path.push_back(min_dis_target);
        min_dis_target = par[min_dis_target.first][min_dis_target.second];
    }

    reverse(target_path.begin(), target_path.end());

    cout << "Path\n";
    for (auto x : target_path) {
        cout << x.first << " " << x.second << "\n";
    }

    cout << min_dis << "\n";
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
