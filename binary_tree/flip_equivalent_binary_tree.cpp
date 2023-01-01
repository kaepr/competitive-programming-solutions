#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 and !root2) {
            return true;
        }

        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }

        bool f1 = flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
        bool f2 = flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
        return f1 || f2;
    }
};