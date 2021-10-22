#include <bits/stdc++.h>
using namespace std;


class node {
public:
	node* left;
	node* right;
};


class trie {
	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int n) {
		node* tmp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;
			if (bit == 0) {
				if (tmp->left == NULL) {
					tmp->left = new node();
				}
				tmp = tmp->left;
			} else {
				if (tmp->right == NULL) {
					tmp->right = new node();
				}
				tmp = tmp->right;
			}
		}
	}

	int max_xor_helper(int value) {
		int cur = 0;
		node* tmp = root;

		for (int j = 31; j >= 0; j--) {
			int bit = (value >> j) & 1;
			if (bit == 0) {
				if (tmp->right != NULL) {
					tmp = tmp->right;
					cur += 1 << j;
				} else {
					tmp = tmp->left;
				}
			} else {
				if (tmp->left != NULL) {
					tmp = tmp->left;
					cur += 1 << j;
				} else {
					tmp = tmp->right;
				}
			}
		}

		return cur;
	}

	int max_xor(int* input, int n) {
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int val = input[i];
			insert(val);
		}

		for (int i = 0; i < n; i++) {
			int cxor = max_xor_helper(input[i]);
			mx = max(mx, cxor);
		}

		return mx;
	}
};


int main() {
	int input[] = {3, 10, 5, 25, 9, 2};
	int n = 6;
	trie t;

	cout << t.max_xor(input, n) << "\n";

	return 0;
}

