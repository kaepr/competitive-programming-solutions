#include <bits/stdc++.h>
using namespace std;

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


node* buildTreeLevelOrder() {
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* cur = q.front();
		q.pop();

		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1) {
			cur->left = new node(c1);
			q.push(cur->left);
		}

		if (c2 != -1) {
			cur->right = new node(c2);
			q.push(cur->right);
		}
	}

	return root;
}


int height(node* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + max(height(root->left), height(root->right));
}

// O(N^2)
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
	HDPair p;
	if (root == NULL) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	HDPair left = diameterOptimized(root->left);
	HDPair right = diameterOptimized(root->right);

	p.height = 1 + max(left.height, right.height);
	int D1 = left.height + right.height;
	int D2 = left.diameter;
	int D3 = right.diameter;
	p.diameter = max(D1, max(D2, D3));
	return p;
}

int replaceWithDescendants(node* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int tmp = root->data;

	int SL = replaceWithDescendants(root->left);
	int SR = replaceWithDescendants(root->right);

	root->data = SL + SR;
	return tmp + root->data;
}

pair<int, bool> isHeightBalanced(node* root) {
	pair<int, bool> p, L, R;
	if (root == NULL) {
		p.first = 0;
		p.second = true;
		return p;
	}

	L = isHeightBalanced(root->left);
	R = isHeightBalanced(root->right);
	p.first = 1 + max(L.first, R.first);

	if (abs(L.first - R.first) <= 1 and L.second and R.second) {
		p.second = true;
	} else {
		p.second = false;
	}
	return p;
}

class Pair() {
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

	Pair left = maxSubsetSum(root->left);
	Pair right = maxSubsetSum(root->right);

	p.inc = root->data + left.exc + right.exc;
	p.exc = max(left.inc, left.exc) + max(right.exc + right.inc);
	return p;
}

void printAtLevelK(node* root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << " ";
		return;
	}
	printAtLevelK(k - 1);
	printAtLevelK(k - 1;)

}

void solve() {
	// node* root = buildTree();
	// node* root = buildTreeLevelOrder();
	// levelOrder(root);
	// cout << diameter(root) << "\n";
	// 	cout << diameter(root) << "\n";
	// replaceWithDescendants(root);
	// levelOrder(root);

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right = new node(9);
	root->right->right->right->right = new node(10);

	node* target = root->left->right;
	int k = 2;
	printNodesAtDistanceK(root, target, k);

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
