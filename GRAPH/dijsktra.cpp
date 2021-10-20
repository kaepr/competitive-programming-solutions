#include <bits/stdc++.h>
using namespace std;

class Graph {
	int N;
	vector<vector<pair<int, int>>> adj;

public:
	Graph(int totalVertices) {
		N = totalVertices;
		adj.clear();
		for (int i = 0; i <= N; i++) {
			vector<pair<int, int>> tmp;
			adj.push_back(tmp);
		}
	}

	void addEdge(int i, int j, int wt, bool undir = true) {
		adj[i].push_back(make_pair(j, wt));
		if (undir) {
			adj[j].push_back(make_pair(i, wt));
		}
	}

	int dijkstra(int src, int dest) {
		vector<int> dist(N, INT_MAX);
		set<pair<int, int>> st;

		dist[src] = 0;
		st.insert(make_pair(0, src));
		while (!st.empty()) {
			auto it = st.begin();
			int node = it->second;
			int nodeDist = it->first;
			st.erase(it);

			for (auto childPair : adj[node]) {

				int childNode = childPair.second;
				int curEdge = childPair.first;

				if (nodeDist + curEdge < dist[childNode]) {

					auto f = st.find(make_pair(dist[childNode], childNode));
					if (f != st.end()) {
						st.erase(f);
					}

					dist[childNode] = nodeDist + curEdge;
					st.insert(make_pair(dist[childNode], childNode));
				}
			}
		}

		// Can also print all distances here
		cout << "Hello\n";
		return dist[dest];
	}




	void printGraph() {
		cout << "Graph Adjacency List\n";
		for (int i = 1; i <= N; i++) {
			cout << i << " -> ";
			for (auto x : adj[i]) {
				cout << x.first << " ";
			}
			cout << "\n";
		}
	}



};

int main() {
	Graph g(5);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 2);
	g.addEdge(1, 3, 4);
	g.addEdge(4, 2, 2);
	g.addEdge(4, 5, 3);

	cout << g.dijkstra(1, 5) << "\n";

	// g.printGraph();
	// // g.bfs(1, 6);

	// g.dfs(1);
	// if (g.containsCycle()) {
	// 	cout << "Cycle yes\n";
	// } else {
	// 	cout << "Cycle No\n";
	// }

	int n, m, source;
	cin >> n >> m;
	vector<pair<int, int> > g[n + 1]; 	// 1-indexed adjacency list for of graph

	int a, b, wt;
	for (int i = 0; i < m ; i++) {
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b, wt));
		g[b].push_back(make_pair(a, wt));
	}

	cin >> source;

	// Dijkstra's algorithm begins from here
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // min-heap ; In pair => (dist,from)
	vector<int> distTo(n + 1, INT_MAX); 	// 1-indexed array for calculating shortest paths;

	distTo[source] = 0;
	pq.push(make_pair(0, source));	// (dist,from)

	while ( !pq.empty() ) {
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int, int> >::iterator it;
		for ( it = g[prev].begin() ; it != g[prev].end() ; it++) {
			int next = it->first;
			int nextDist = it->second;
			if ( distTo[next] > distTo[prev] + nextDist) {
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}

	}

	cout << "The distances from source, " << source << ", are : \n";
	for (int i = 1 ; i <= n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}


/*
NOTES

BFS gives shortest distance in undirected graph


*/