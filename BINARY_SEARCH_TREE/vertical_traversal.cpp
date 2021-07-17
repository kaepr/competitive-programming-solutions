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

void vTraversal(Node *root) {
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (q.empty() == false) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp) {
        for (int y : x.second)
            cout << y << " ";
        cout << endl;
    }
}


void topView(Node *root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (q.empty() == false) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        if (mp.find(hd) == mp.end())
            mp[hd] = (curr->key);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp) {
        cout << x.second << " ";
    }
}


void bottomView(Node *root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (q.empty() == false) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd] = (curr->key);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp) {
        cout << x.second << " ";
    }
}


int main() {

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    vTraversal(root);

    return 0;

}