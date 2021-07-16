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

// O(N) Time Complexity
// O(h) Auxillary Space
void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

// O(N) Time Complexity
// O(h) Auxillary Space
void preorder(Node *root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

// O(N) Time Complexity
// O(h) Auxillary Space
void postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}

// Time Complexity O(N)
// Auxillary Space O(H)
int heightTree(Node *root) {
	if (root == NULL) {
		return 0;
	} else {
		return 1 + max(heightTree(root->left), heightTree(root->right));
	}
}


// Time Complexity O(N)
// Auxillary Space O(H)
void printAtKDistance(Node *root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->key << " ";
	} else {
		printAtKDistance(root->left, k - 1);
		printAtKDistance(root->right, k - 1);
	}
}

// Time Complxity O(N)
void printLevel(Node *root) {
	if (root == NULL) {
		return;
	}
	queue<Node *> q;
	q.push(root);
	while (q.empty() == false) {
		Node *curr = q.front();
		q.pop();
		cout << curr->key << " ";
		if (curr->left != NULL) {
			q.push(curr->left);
		}
		if (curr->right != NULL) {
			q.push(curr->right);
		}
	}
}

// Level Order with new lines for each level
vector<vector<int>> levelOrder(Node *root) {
	vector<vector<int>> ans;
	if (root == NULL) {
		return ans;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		vector<int> tmp;
		while (n > 0) {
			Node* node = q.front();
			q.pop();
			tmp.push_back(node->key);

			if (node->left != NULL) {
				q.push(node->left);
			}

			if (node->right != NULL) {
				q.push(node->right);
			}
			n--;
		}
		ans.push_back(tmp);
	}
	return ans;
}

// Time => O(n)
// Aux Space => O(h)
int getTreeSize(Node *root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

// Time => O(N)
// Aux => O(H)
int maximumElement(Node *root) {
	if (root == NULL) {
		return INT_MIN;
	}

	return max(root->key, max(maximumElement(root->left), maximumElement(root->right)));
}

// Time => O(N)
// Aux Space => O(H)
int maxlevel = 0;
void leftViewRecursive(Node *root, int level) {
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->key << " ";
		maxlevel = level;
	}

	leftViewRecursive(root->left, level + 1);
	leftViewRecursive(root->right, level + 1);
}

void leftViewIterative(Node *root) {
	queue<Node*> q;
	q.push(root);
	vector<int> ans;
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Node* cur = q.front();
			q.pop();

			if (i == 0) {
				ans.push_back(cur->key);
			}

			if (cur->left != NULL) {
				q.push(cur->left);
			}

			if (cur->right != NULL) {
				q.push(cur->right);
			}
		}
	}

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

// Time => O(N)
// Aux Space => O(H)
bool childrenSum(Node *root) {
	if (root == NULL) {
		return true;
	}

	// Checks for leaf node
	if (root->right == NULL && root->left == NULL) {
		return true;
	}

	int sum = 0;
	if (root->right != NULL) {
		sum += root->right->key;
	}

	if (root->left != NULL) {
		sum += root->left->key;
	}

	bool f = root->key == sum && childrenSum(root->left) && childrenSum(root->right);
	return  f;
}

// Time => O(N)
// Aux Space => O(H)
bool isBalancedNaive(Node *root) {
	if (root == NULL) {
		return true;
	}
	int lh = heightTree(root->left);
	int rh = heightTree(root->right);
	bool f = abs(lh - rh) <= 1;
	f = f && isBalancedNaive(root->left) && isBalancedNaive(root->right);
	return f;
}

int isBalaned(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int lh = isBalaned(root->left);
	if (lh == -1) {
		return -1;
	}

	int rh = isBalaned(root->right);
	if (rh == -1) {
		return -1;
	}

	if (abs(lh - rh) > 1) {
		return -1;
	} else {
		return max(lh, rh) + 1;
	}
}


// Time => O(N)
// Aux Space => O(H)
int maximumWidth(Node *root) {
	int res = 0;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		res = max(res, n);
		while (n > 0) {
			Node* cur = q.front();
			q.pop();

			if (cur->left != NULL) {
				q.push(cur->left);
			}

			if (cur->right != NULL) {
				q.push(cur->right);
			}

			n--;
		}
	}

	return res;
}

//Constructor Tree from inorder and preorder
// In Order = Left Root Right
// Pre Order = Root Left Right
// Time - O(n^2)
// Can be optimized to O(n) is hashing used
int preIndex = 0;
Node *cTree(int in[], int pre[], int is, int ie) {
	if (is > ie) {
		return NULL;
	}
	Node *root = new Node(pre[preIndex]);
	preIndex++;
	int inIndex = 0;
	for (int i = is; i <= ie; i++) {
		if (in[i] == root->key) {
			inIndex = i;
			break;
		}
	}

	root->left = cTree(in, pre, is, inIndex - 1);
	root->right = cTree(in, pre, inIndex + 1, ie);
	return root;
}

void printSpiral(Node* root) {
	queue<Node*> q;
	q.push(root);
	vector<vector<int>> ans;
	while (!q.empty()) {
		int n = q.size();
		vector<int> tmp;
		while (n > 0) {

			Node* cur = q.front();
			q.pop();
			tmp.push_back(cur->key);

			if (cur->left != NULL) {
				q.push(cur->left);
			}

			if (cur->right != NULL) {
				q.push(cur->right);
			}

			n--;
		}
		ans.push_back(tmp);
	}

	int ptr = 0;
	for (auto x : ans) {
		if (ptr % 2 == 0) {
			for (auto y : x) {
				cout << y << " ";
			}
		} else {
			reverse(x.begin(), x.end());
			for (auto y : x) {
				cout << y << " ";
			}
		}
		ptr++;
		cout << "\n";
	}

}

// O(n^2)
int getDiameter(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int d1 = 1 + heightTree(root->left) + heightTree(root->right);
	int d2 = getDiameter(root->left);
	int d3 = getDiameter(root->right);
	return max(d1, max(d2, d3));
}

// Modified height function to calculate diameter
int res = 0;
int diameterOptimized(Node *root) {
	if (root == NULL) {
		return 0;
	}
	int lh = diameterOptimized(root->left);
	int rh = diameterOptimized(root->right);
	res = max(res, 1 + lh + rh);
	return 1 + max(lh, rh);
}


Node* initializeTree() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->left->left->left = new Node(60);
	root->left->left->left->left = new Node(70);
	return root;
}

int main() {
	// root holds the address to a node structure
	Node* root = initializeTree();

	inorder(root);
	cout << "\n";
	preorder(root);
	cout << "\n";
	postorder(root);
	cout << "\n";

	cout << heightTree(root) << "\n";

	cout << "Level order traversal\n";
	printLevel(root);
	cout << "\n";

	cout << "Level Order Traversal Again\n";
	vector<vector<int>> ans = levelOrder(root);
	for (auto x : ans) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}

	cout << "Tree Size\n";
	cout << getTreeSize(root) << "\n";


	cout << "Maximum Element\n";
	cout << maximumElement(root) << "\n";

	cout << "Left View\n";
	leftViewRecursive(root, 1);
	cout << "\n";
	leftViewIterative(root);

	// as root is variable which holds addresses,
	// just assigning it a new one
	// no need to use *root
	// root = new Node(20);
	// root->left = new Node(8);
	// root->right = new Node(12);
	// root->right->left = new Node(3);
	// root->right->right = new Node(9);
	cout << "Is children sum\n";
	cout << childrenSum(root) << "\n";

	cout << "Is balanced\n";
	if (isBalaned(root)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	cout << "Width\n";
	cout << maximumWidth(root) << "\n";
	cout << "----------\n";
	int in[] = {20, 10, 40, 30, 50};
	int pre[] = {10, 20, 30, 40, 50};
	int n = sizeof(in) / sizeof(in[0]);
	Node *root1 = cTree(in, pre, 0, n - 1);
	inorder(root1);
	cout << "\n";


	cout << "Level Order\n";
	printLevel(root);

	cout << "Spiral Print\n";
	printSpiral(root);






	return 0;
}


/*
Binary tree to DLL

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  Node(int k){
      key=k;
      left=right=NULL;
  }
};


void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->key<<" ";
        curr=curr->right;
    }cout<<endl;
}



Node *BTToDLL(Node *root){
    if(root==NULL)return root;
    static Node* prev = NULL;
    Node *head=BTToDLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}


int main() {

	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);

	Node *head=BTToDLL(root);
	printlist(head);
}

*/