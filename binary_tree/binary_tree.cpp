#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

class node {
public:
	int data;
	node *left;
	node *right;

	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

// input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

void levelOrderPrint(node* root) {
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

node* levelOrderBuild() {
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* current = q.front();
		q.pop();

		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1) {
			current->left = new node(c1);
			q.push(current->left);
		}

		if (c2 != -1) {
			current->right = new node(c2);
			q.push(current->right);
		}
	}

	return root;
}

int height(node* root) {
	if (root == NULL) {
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);
	return 1 + max(lh, rh);
}

// largest distance between any two nodes in a tree
// unoptimized O(n^2)
int diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);

	return max(D1, max(D2, D3));
}


class HDPair {
public:
	int height;
	int diameter;
};

HDPair diameterOptimized(node* root) {
	if (root == NULL) {
		HDPair p;
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	HDPair p;
	HDPair left = diameterOptimized(root->left);
	HDPair right = diameterOptimized(root->right);

	p.height = 1 + max(left.height, right.height);
	int D1 = left.height + right.height;
	int D2 = left.diameter;
	int D3 = right.diameter;
	p.diameter = max(D1, max(D2, D3));

	return p;
}

int replaceWithSum(node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	int tmp = root->data;
	root->data = replaceWithSum(root->left) + replaceWithSum(root->right);
	return root->data + tmp;
}

pair<int, bool> isHeightBalanced(node *root) {
	pair<int, bool> p, Left, Right;
	if (root == NULL) {
		p.first = 0;
		p.second = true;
		return p;
	}

	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);

	int height = max(Left.first, Right.first) + 1;

	if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second) {
		return make_pair(height, true);
	}
	return make_pair(height, false);
}

// max subset
class Pair {
public:
	int inc;
	int exc;
};

Pair maxSubsetSum(node* root) {
	Pair p;
	if (root == NULL) {
		p.inc = p.exc = 0;
		return p;
	}

	Pair Left = maxSubsetSum(root->left);
	Pair Right = maxSubsetSum(root->right);

	p.inc = root->data + Left.exc + Right.exc;
	p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);
	return p;
}

// -----

void printAtLevelK(node *root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);
}

int printNodesAtDistanceK(node* root, node* target, int k) {
	// base case
	if (root == NULL) {
		return -1;
	}

	// reach target node
	if (root == target) {
		printAtLevelK(target, k);
		return 0;
	}

	// other case
	int DL = printNodesAtDistanceK(root->left, target, k);
	if (DL != -1 ) {
		if (DL + 1 == k) {
			cout << root->data;
		} else {
			printAtLevelK(root->right, k - 2 - DL);
		}
		return 1 + DL;
	}

	int DR = printNodesAtDistanceK(root->right, target, k);
	if (DR != -1 ) {
		if (DR + 1 == k) {
			cout << root->data;
		} else {
			printAtLevelK(root->left, k - 2 - DR);
		}
		return 1 + DR;
	}

	return -1;
}

// -----
void traverseTree(node* root, int d, map<int, vector<int>> &m) {
	if (root == NULL) {
		return;
	}

	m[d].push_back(root->data);
	traverseTree(root->left, d - 1, m);
	traverseTree(root->right, d + 1, m);
}

void verticalOrderPrint(node* root) {
	map<int, vector<int>> m;
	int d = 0;

	traverseTree(root, d, m);

	for (auto p : m) {
		int key = p.first;
		vector<int> line = p.second;
		for (auto data : line) {
			cout << data << " ";
		}
		cout << "\n";
	}

}


int main() {
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right = new node(9);

	// cout << "HI\n";

	levelOrderPrint(root);

	HDPair res = diameterOptimized(root);

	cout << res.diameter << "\n";

	return 0;
}
