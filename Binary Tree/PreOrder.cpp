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
        void preorderRecursive(TreeNode* root, vector<int> &result) {
            if (root == NULL)
                return;
            result.push_back(root->val);
            preorderRecursive(root->left, result);
            preorderRecursive(root->right, result);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            preorderRecursive(root, result);
            return result;
        }
    };