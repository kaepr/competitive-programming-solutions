#include <bits/stdc++.h>
using namespace std;

class Graph {
	int N;
	vector<vector<int>> adj;

public:
	Graph(int totalVertices) {
		N = totalVertices;
		adj.clear();
		for (int i = 0; i <= N; i++) {
			vector<int> tmp;
			adj.push_back(tmp);
		}
	}

	void addEdge(int i, int j, bool undir = true) {
		adj[i].push_back(j);
		if (undir) {
			adj[j].push_back(i);
		}
	}

	void printGraph() {
		cout << "Graph Adjacency List\n";
		for (int i = 1; i <= N; i++) {
			cout << i << " -> ";
			for (auto x : adj[i]) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}

	void bfs(int source, int destination = -1) {
		queue<int> q;
		vector<bool> vis(N, false);
		vector<int> parent(N, -1);
		vector<int> dist(N, 0);

		q.push(source);
		vis[source] = true;
		parent[source] = -1;
		dist[source] = 0;

		vector<int> traversal;

		while (!q.empty()) {
			int f = q.front();
			q.pop();
			traversal.push_back(f);

			for (auto x : adj[f]) {
				if (!vis[x]) {
					q.push(x);
					parent[x] = f;
					dist[x] = dist[f] + 1;
					vis[x] = true;
				}
			}
		}

		cout << "BFS Traversal from " << source << "\n";
		for (auto x : traversal) {
			cout << x << " ";
		}
		cout << "\n";

		cout << "Shortest Distance to all nodes from " << source << "\n";
		for (auto i = 1; i <= N; i++) {
			cout << "Node : " << i << ", Dist : " << dist[i] << "\n";
		}

		if (destination != -1) {
			vector<int> path;
			int node = destination;
			while (node != -1) {
				path.push_back(node);
				node = parent[node];
			}
			reverse(path.begin(), path.end());
			cout << "Path b/w S " << source << " and D " << destination << "\n";
			for (auto x : path) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}

	void dfsHelper(int node, vector<bool> &vis, vector<int> &path) {
		vis[node] = true;
		path.push_back(node);
		for (auto x : adj[node]) {
			if (!vis[x]) {
				dfsHelper(x, vis, path);
			}
		}
	}

	void dfs(int source) {
		vector<bool> vis(N, false);
		vector<int> traversal;
		dfsHelper(source, vis, traversal);

		cout << "DFS Traversal from " << source << "\n";
		for (auto x : traversal) {
			cout << x << " ";
		}
		cout << "\n";
	}

	bool dfsCycleHelper(int node, vector<bool> &vis, int parent) {
		vis[node] = true;
		for (auto x : adj[node]) {
			if (!vis[x]) {
				bool nbrFoundCycle = dfsCycleHelper(x, vis, node);
				if (nbrFoundCycle) {
					return true;
				}
			} else if (x != parent) {
				// implies child is visited
				// but its not the parent of current node
				// in current call
				return true;
			}
		}
		return false;
	}

	bool containsCycle() {
		// assuming single component
		vector<bool> vis(N, false);
		return dfsCycleHelper(1, vis, -1);
	}

	bool dfsCycleHelperDirected(int src, vector<bool> &vis, vector<bool> &st) {
		vis[src] = true;
		st[src] = true;

		for (auto child : adj[src]) {
			if (st[src]) {
				return true;
			} else if (!vis[child]) {
				bool nbrFoundCycle = dfsCycleHelperDirected(child, vis, st);
				if (nbrFoundCycle) {
					return true;
				}
			}
		}

		st[src] = false;
		return false;
	}

	bool containsCycleDirected() {
		vector<bool> vis(N, false);
		vector<bool> stack(N, false);

		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				if (dfsCycleHelperDirected(i, vis, stack)) {
					return true;
				}
			}

		}
		return false;
	}

};

int main() {
	Graph g(6);
	g.addEdge(1, 6);
	g.addEdge(2, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(5, 6);

	g.printGraph();
	// g.bfs(1, 6);

	g.dfs(1);
	if (g.containsCycle()) {
		cout << "Cycle yes\n";
	} else {
		cout << "Cycle No\n";
	}

}


/*
NOTES

BFS gives shortest distance in undirected graph


*/