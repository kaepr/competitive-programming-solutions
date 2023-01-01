#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	Node(int k) {
		key = k;
		left = NULL;
		right = NULL;
	}
};

// Time - O(h), Aux Space - O(h)
bool search(Node* root, int x) {
	if (root == NULL) {
		return false;
	}
	if (root->key == x) {
		return true;
	} else if (root->key > x) {
		return search(root->left, x);
	} else {
		return search(root->right, x);
	}
}

Node *insertRecursive(Node *root, int x) {
	if (root == NULL)
		return new Node(x);
	if (root->key < x)
		root->right = insertRecursive(root->right, x);
	else if (root->key > x)
		root->left = insertRecursive(root->left, x);
	return root;
}


Node *insertIterative(Node *root, int x) {
	Node *temp = new Node(x);
	Node *parent = NULL, *curr = root;
	while (curr != NULL) {
		parent = curr;
		if (curr->key > x)
			curr = curr->left;
		else if (curr->key < x)
			curr = curr->right;
		else
			return root;
	}
	if (parent == NULL)
		return temp;
	if (parent->key > x)
		parent->left = temp;
	else
		parent->right = temp;
	return root;
}


void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}


Node *getSuccessor(Node *curr) {
	curr = curr->right;
	while (curr != NULL && curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node *delNode(Node *root, int x) {
	if (root == NULL)
		return root;
	if (root->key > x)
		root->left = delNode(root->left, x);
	else if (root->key < x)
		root->right = delNode(root->right, x);
	else {
		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else {
			Node *succ = getSuccessor(root);
			root->key = succ->key;
			root->right = delNode(root->right, succ->key);
		}
	}
	return root;
}


Node *floor(Node *root, int x) {
	Node *res = NULL;
	while (root != NULL) {
		if (root->key == x)
			return root;
		else if (root->key > x)
			root = root->left;
		else {
			res = root;
			root = root->right;
		}
	}
	return res;
}


Node *ceil(Node *root, int x) {
	Node *res = NULL;
	while (root != NULL) {
		if (root->key == x)
			return root;
		else if (root->key < x)
			root = root->right;
		else {
			res = root;
			root = root->left;
		}
	}
	return res;
}

Node* initializeTree() {
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(18);
	return root;
}

int main() {

	Node *root = initializeTree();
	int x = 16;

	if (search(root, x))
		cout << "Found\n";
	else
		cout << "Not Found\n";

	root = insertIterative(root, x);
	inorder(root);

	return 0;
}