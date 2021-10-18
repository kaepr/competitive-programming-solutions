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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        visited[target] = true;
        int level = 0;
        queue.push(target);

        while (!queue.empty()) {
            int sz = queue.size();
            if (level >= k) {
                break;
            }

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = queue.front();
                queue.pop();
                if (cur->left and !visited[cur->left]) {
                    queue.push(cur->left);
                    visited[cur->left] = true;
                }

                if (cur->right and !visited[cur->right]) {
                    queue.push(cur->right);
                    visited[cur->right] = true;
                }

                if (parent_track[cur] and !visited[parent_track[cur]]) {
                    queue.push(parent_track[cur]);
                    visited[parent_track[cur]] = true;
                }

            }
            level++;
        }

        vector<int> res;
        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            res.push_back(cur->val);
        }

        return res;
    }
};

void print(vector<int>&answer, TreeNode *blocker, TreeNode *root, int k)
{
    if (root == NULL || k < 0 || root == blocker)
        return;
    if (k == 0)
    {
        answer.push_back(root->val);
        return;
    }
    print(answer, blocker, root->left, k - 1);
    print(answer, blocker, root->right, k - 1);

}

int find_path(TreeNode *root, TreeNode *target, int k, vector<int>&answer)
{
    if (root == NULL)
        return -1;
    if (root == target)
    {
        print(answer, NULL, root, k);
        return 1;
    }

    int lc = find_path(root->left, target, k, answer);
    if (lc != -1)
    {
        print(answer, root->left, root, k - lc);

        return lc + 1;
    }
    int rc = find_path(root->right, target, k, answer);
    if (rc != -1)
    {

        print(answer, root->right, root, k - rc);

        return rc + 1;
    }
    return  -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    vector<int>answer;
    int temp = find_path(root, target, k, answer);
    return answer;


}