#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


int prevv = INT_MIN;
bool isBST(Node* root)
{
    if (root == NULL)
        return true;

    if (isBST(root->left) == false)return false;

    if (root->key <= prevv)return false;
    prevv = root->key;

    return isBST(root->right);
}

int main() {

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;

}

class Solution {
public:
    bool isValid(TreeNode* root, long long mn, long long mx) {
        if (root == NULL) {
            return true;
        }

        if ((long long)root->val <= mn or (long long)root->val >= mx) {
            return false;
        }

        bool leftHalf = isValid(root->left, mn, root->val);
        bool rightHalf = isValid(root->right, root->val, mx);
        return leftHalf and rightHalf;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};


bool isBSTUtil(struct Node* root, Node *&prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

bool isBST(Node *root)
{
    Node *prev = NULL;
    return isBSTUtil(root, prev);
}
