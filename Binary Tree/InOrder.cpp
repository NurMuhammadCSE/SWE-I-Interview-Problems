#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        void inorderRecursive(TreeNode* root, vector<int>& result) {
            if (root == NULL)
                return;
            inorderRecursive(root->left, result);
            result.push_back(root->val);
            inorderRecursive(root->right, result);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            inorderRecursive(root, result);
            return result;
        }
    };