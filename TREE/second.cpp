#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* right;
	struct Node* left;
	Node(int k) {
		key = k;
		right = NULL;
		left = NULL;
	}
};

// O(N), although traversed several times
bool findPath(Node *root, vector<Node *> &p, int n) {
	if (root == NULL) {
		return false;
	}
	p.push_back(root);
	if (root->key == n) {
		return true;
	}

	if (findPath(root->left, p, n) || findPath(root->right, p, n)) {
		return true;
	}

	p.pop_back();
	return false;
}

Node* lca(Node *root, int n1, int n2) {
	vector<Node *> path1, path2;
	if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) {
		return NULL;
	}

	for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++) {
		if (path1[i + 1] != path2[i + 1]) {
			return path1[i];
		}
	}
	return NULL;
}

int countNodesComplete(Node* root) {
	int lh = 0, rh = 0;
	Node* cur = root;
	while (cur != NULL) {
		lh++;
		cur = cur->left;
	}
	cur = root;
	while (cur != NULL) {
		rh++;
		cur = cur->right;
	}
	if (lh == rh) {
		return pow(2, lh) - 1;
	} else {
		return 1 + countNodesComplete(root->left) + countNodesComplete(root->right);
	}
}


Node* initializeTree() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(40);
	root->right->right = new Node(50);

	return root;
}

const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr) {
	if (root == NULL) {
		arr.push_back(EMPTY);
		return;
	}
	arr.push_back(root->key);
	serialize(root->left, arr);
	serialize(root->right, arr);
}


Node *deSerialize(vector<int> &arr, int &index) {
	if (index == arr.size())
		return NULL;
	int val = arr[index];
	index++;
	if (val == EMPTY)return NULL;
	Node *root = new Node(val);
	root->left = deSerialize(arr, index);
	root->right = deSerialize(arr, index);
	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}


void iterativeInorder(Node* root) {
	cout << "\nIterative Inorder\n";
	stack<Node *> st;
	Node *cur = root;
	while (cur != NULL || !st.empty()) {
		while (cur != NULL) {
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		cout << cur->key << " ";
		cur = cur->right;
	}
}


void iterativePreorder(Node* root) {
	cout << "\nIterative Preorder\n";
	if (root == NULL) {
		return;
	}

	stack<Node *> st;
	st.push(root);
	while (!st.empty()) {
		Node* cur = st.top();
		cout << cur->key << " ";
		st.pop();
		if (cur->right != NULL) {
			st.push(cur->right);
		}

		if (cur->left != NULL) {
			st.push(cur->left);
		}
	}
}





int main() {

	Node* root = initializeTree();
	int n1 = 20, n2 = 50;
	Node *ans = lca(root, n1, n2);
	cout << "LCA: " << ans->key << "\n";

	cout << "Nodes = " << countNodesComplete(root) << "\n";

	vector<int> arr;
	serialize(root, arr);
	for (int x : arr) {
		cout << x << " ";
	}
	cout << "\n";

	int index = 0;
	Node *root_new = deSerialize(arr, index);
	inorder(root_new);

	iterativeInorder(root);
	iterativePreorder(root);

	return 0;
}

