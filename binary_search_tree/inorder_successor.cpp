#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        if (x->right != NULL) {
            Node* tmp = x->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            return tmp;
        }
        Node* tmp = root;
        Node* succ = NULL;
        while (tmp != NULL) {
            if (tmp->data > x->data) {
                succ = tmp;
                tmp = tmp->left;
            } else if (tmp->data < x->data) {
                tmp = tmp->right;
            } else {
                break;
            }
        }

        return succ;

    }
};


// class Node
// {
// public:
//     int key;
//     Node *left;
//     Node *right;
//     Node *parent;
// };

// Node* findInOrderSuccessor( Node *inputNode )
// {
//     // your code goes here
//     //find the left most child of right subtree if it exists
//     if (inputNode->right != NULL) {
//         Node*temp = inputNode->right;
//         while (temp->left != NULL) {
//             temp = temp->left;
//         }
//         return temp;
//     }
//     else {
//         // traverse the parent till node is a right child of its parent
//         Node* parent = inputNode->parent;
//         Node*temp = inputNode;
//         while (parent != NULL and parent->right == temp) {
//             temp = parent;
//             parent = temp->parent;
//         }
//         return parent;
//     }
// }