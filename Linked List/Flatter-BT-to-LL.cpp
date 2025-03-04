#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val) {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    obj.flatten(root);

    while (root) {
        cout << root->val << " ";
        root = root->right;
    }

    return 0;
}