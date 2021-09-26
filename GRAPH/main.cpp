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

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<bool> vis(MAXN, false);
vector<bool> local_vis(MAXN, false);
vector<int> top_sort;
int n;

/*
Check for cycle in undirected graph
*/

bool undirected_graph_cycle_chk(int node, vector<bool> &vis, int parent) {
	vis[node] = true;
	for (auto x : adj[node]) {
		if (!vis[x]) {
			bool found_cycle = undirected_graph_cycle_chk(x, vis, node);
		} else {
			// x is visited
			// make sure it is not parent of the
			// current node

			// if cur node is not parent
			// then proved cycle exists
			if (x != parent) {
				return true;
			}
		}
	}
	return false;
}


/*
Check for cycle in directed Graph
*/
bool directed_cycle_graph(int node) {
	vis[node] = true;
	local_vis[node] = true;

	// for (int i = 1; i <= n; i++) {
	// 	cout << vis[i] << " ";
	// }
	// cout << "\n";

	// trace(node);
	for (auto x : adj[node]) {
		// trace(x);
		// if backedge found, return
		// else keep searching for backedge
		if (local_vis[x]) {
			return true;
		} else if (!vis[x]) {
			bool chk = directed_cycle_graph(x);
			if (chk) {
				return true;
			}
		}
	}

	local_vis[node] = false;
	return false;
}

/*
Topological Sort
*/
void topological_sort(int node, stack<int> &st) {
	vis[node] = 1;

	for (auto x : adj[node]) {
		if (!vis[x]) {
			topological_sort(x, st);
		}
	}

	st.push(node);
}


void solve()
{
	cin >> n;

	fill(vis.begin(), vis.end() + n, false);
	top_sort.clear();
	fill(local_vis.begin(), local_vis.end() + n, false);

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}

	for (int i = 0; i < n; i++) {

		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++) {
			int x;
			cin >> x;
			adj[x].push_back(i + 1);
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	trace(i);
	// 	for (auto x : adj[i]) {
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (directed_cycle_graph(i)) {
				// cout << "Contains cycle\n";
				cout << "-1\n";
				return;
			}
		}
	}

	fill(vis.begin(), vis.end() + n, false);

	stack<int> st;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			topological_sort(i, st);
		}
	}


	while (!st.empty()) {
		top_sort.PB(st.top());
		st.pop();
	}


	// cout << "topological sort\n";
	// for (auto x : top_sort) {
	// 	cout << x << " ";
	// }
	// cout << "\n";


	int ans = 0;
	vi dp(n + 1 , 1);
	for (int i = 0; i < n; i++) {
		int cur = top_sort[i];

		for (auto x : adj[cur]) {
			if (x > cur) {
				dp[x] = max(dp[x], dp[cur]);
			} else {
				dp[x] = max(dp[x], dp[cur] + 1);
			}
		}

		ans = max(ans, dp[cur]);
	}

	cout << ans << "\n";

	// trace(ans);

}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t > 0)
	{
		solve();
		t--;
	}

	return 0;
}
