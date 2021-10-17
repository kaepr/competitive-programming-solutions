#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

const ll MOD = 1e9 + 7;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	node*n = new node(d);
	n->left = buildTree();
	n->right  = buildTree();
	return n;
}

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* tmp = q.front();
		if (tmp == NULL) {
			cout << "\n";
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			q.pop();
			cout << tmp->data << " ";
			if (tmp->left) {
				q.push(tmp->left);
			}

			if (tmp->right) {
				q.push(tmp->right);
			}
		}
	}
}


void solve() {
	// cout << "HI\n";
	node* root = buildTree();
	levelOrder(root);

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
