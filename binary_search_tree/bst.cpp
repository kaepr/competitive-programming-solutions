#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;
/*

Inorder traversal of BST is sorted

*/

class Node {
public:
	int key;
	Node *left;
	Node *right;

	Node(int key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertNode(Node *root, int key) {
	if (root == NULL) {
		return new Node(key);
	}

	if (key < root->key) {
		root->left = insertNode(root->left, key);
	} else {
		root->right = insertNode(root->right, key);
	}

	return root;
}

void printInOrder(Node *root) {
	if (root == NULL) {
		return;
	}
	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
}

// bool searchNode(Node* root )

Node* sortedArrayToBST(vector<int> arr, int start, int end)
{
	//Return Null if s > e, because no array elements are there
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	Node *root = new Node(arr[mid]);

	//create left & right subtrees recursively
	root->left = sortedArrayToBST(arr, start, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

// Call from Main
// sortedArrayToBST(arr, 0 , n - 1)



// -----------------------------------------------------
int findClosestInBST(Node* root, int target) {
	int closest;
	int diff = INT_MAX;

	Node *tmp = root;

	while (tmp != NULL) {
		int current_diff = abs(tmp->key - target);

		if (current_diff == 0) {
			return tmp->key;
		}

		if (current_diff < diff) {
			diff = cur_diff;
			closest = tmp->value;
		}

		if (tmp->key < target) {
			tmp = tmp->left;
		} else {
			tmp = tmp->right;
		}
	}

	return closest;
}

// BST to sorted linked list
class LinkedList {
public:
	Node *head;
	Node *tail;
};

LinkedList tree2LL(Node *root) {
	LinkedList l;
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	if (root->left == NULL and root->right) {
		l.head = l.tail = root;
		return l;
	}

	if (root->left != NULL and root->right == NULL) {
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}

	if (root->left == NULL and root->right != NULL) {
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}

	LinkedList leftLL = tree2LL(root->left);
	LinkedList rightLL = tree2LL(root->right);

	leftLL.tail->right = root;
	root->right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}

Node* inorderSucc(Node *root, Node *target) {
	if (target->right != NULL) {
		Node* tmp = target->right;
		while (tmp->left != NULL ) {
			tmp = tmp->left;
		}
		return tmp;
	}

	Node *tmp = root;
	Node* succ = NULL;
	while (tmp != NULL) {
		if (tmp->key > target->key) {
			succ = tmp;
			tmp = tmp->left;
		} else if (tmp->key < target->key) {
			tmp = tmp->right;
		} else {
			break;
		}
	}
	return succ;
}


int main() {
	Node* root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

	for (auto x : arr) {
		root = insertNode(root, x);
	}

	printInOrder(root);

	return 0;
}
