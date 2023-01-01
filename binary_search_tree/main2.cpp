#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node* root, int key) {
	if (root == NULL) {
		return new Node(key);
	}

	if (key < root->key) {
		root->left = insert(root->left, key);
	} else {
		root->right = insert(root->right, key);
	}

	return root;
}

void printInOrder(Node* root) {
	if (root) {
		printInOrder(root->left);
		cout << root->key << " ";
		printInOrder(root->right);
	}
}

bool isPresent(Node* root, int key) {
	if (root == NULL) {
		return false;
	}
	if (root->key == key) {
		return true;
	}
	if (root->key > key) {
		return isPresent(root->left, key);
	}
	return isPresent(root->right, key);

}

Node* sortedArrayToBST(vector<int> arr, int start, int end) {

	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;
	Node* root = new Node(arr[mid]);
	root->left = sortedArrayToBST(arr, start, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);
	return root;
}


int findClosestInBST(Node* root, int target) {
	int closest;
	int diff = INT_MAX;
	Node* tmp = root;
	while (!tmp) {
		int cur_diff = abs(tmp->key - target);
		if (cur_diff == 0) {
			return tmp->key;
		}

		if (cur_diff < diff) {
			diff = cur_diff;
			closest = tmp->key;
		}

		if (tmp->key < target) {
			tmp = tmp->right;
		} else {
			tmp = tmp->left;
		}
	}

	return closest;
}

// BST to Sorted LinkedList =========
class LinkedList {
public:
	Node* head;
	Node* tail;
};

// Post Order Traversal
LinkedList tree2LL(Node* root) {
	LinkedList l;
	if (root == NULL) {
		l.head = NULL;
		l.tail = NULL;
		return l;
	}

	if (root->left == NULL and root->right == NULL) {
		l.head = root;
		l.tail = root;
		return l;
	} else if (root->left != NULL and root->right == NULL) {
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	} else if (root->left == NULL and root->right != NULL) {
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
	} else {
		LinkedList leftLL = tree2LL(root->left);
		LinkedList rightLL = tree2LL(root->right);

		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}

	return l;
}


void solve() {
	Node* root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for (int x : arr) {
		root = insert(root, x);
	}

	printInOrder(root);
	cout << "\n";

	LinkedList l = tree2LL(root);
	Node* tmp = l.head;

	while (tmp != NULL) {
		cout << tmp->key << " -> ";
		tmp = tmp->right;
	}

}

int main() {
	solve();
	return 0;
}