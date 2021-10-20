#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Node {
public:
	int x;
	int y;
	int dist;

	Node(int x, int y, int dist) {
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

struct cmp {
	bool operator()(const Node& x, const Node& y) { return x.dist < y.dist; }
};

int shortest_path(vector<vector<int>> grid) {
	int m = grid.size();
	int n = grid[0].size();

	int i = 0, j = 0;
	vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX));

	dist[i][j] = grid[i][j];
	set<Node, cmp> st;

	st.insert(Node(i, j, grid[i][j]));

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	while (!st.empty()) {
		auto it = st.begin();
		int cx = it->x;
		int cy = it->y;
		int cd = it->dist;
		st.erase(it);

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and cd + grid[nx][ny] < dist[nx][ny]) {

				Node tmp(nx, ny, dist[nx][ny]);
				if (st.find(tmp) != st.end()) {
					st.erase(st.find(tmp));
				}

				int nd = grid[nx][ny] + cd;
				dist[nx][ny] = nd;
				st.insert(Node(nx, ny, nd));
			}
		}
	}


	return dist[m - 1][n - 1];
}

void solve() {

}

int main() {

	int t = 1;
	cin >> t;
	while (t > 0) {
		solve();
		t--;
	}

	return 0;
}