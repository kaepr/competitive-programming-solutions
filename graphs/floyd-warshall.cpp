#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

/*

All Pair Shortest Path

floyd warshall
use adjacency matrix

for k in [1, n]
    for i in [1, n]
        for j in [1, n]
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


dp(i, j, k) -> shortest path from i to j using (1...k)

*/

int dist[405][405];
int par[405][405];
int n, m;

void printPath(int i, int j) {
    if (i != j)
        printPath(i, par[i][j]);

    cout << j << "\n";
}

void floyd_warshall() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != j) {
                dist[i][j] = 1e9;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = i;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);

        // to find if path exists b/w a and b
        // dist[a][b] = 1
    }

    // finding if path exists
    // reachability
    // for (int k = 1; k <= n; k++) {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
    //         }
    //     }
    // }

    // find shortest cycle
    // dist[i][i] -> shortest length of path which can reach i to i
    // take minimum from all nodes

    // gives shortest path value at dist[a][b]
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }

    // find if negative cycle exists
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[i][i]);
    }

    if (ans < 0) {
        cout << "-ve cycle exists";
    } else {
        cout << "nope";
    }

    // find diameter of graph
    // which is the longest shortest path
    // just get maximum dist(i, j)
}

void solve() {}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
