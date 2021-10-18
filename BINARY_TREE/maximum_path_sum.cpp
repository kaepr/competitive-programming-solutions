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
    int getMaxPathSum(TreeNode* root, int &mx) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = max(0, getMaxPathSum(root->left, mx));
        int rightSum = max(0, getMaxPathSum(root->right, mx));

        mx = max(mx, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        getMaxPathSum(root, mx);
        return mx;
    }
};