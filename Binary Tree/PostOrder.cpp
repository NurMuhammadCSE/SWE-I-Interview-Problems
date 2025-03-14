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
        void postorderRecursive(TreeNode* root, vector<int>& result) {
            if (root == NULL)
                return;
            postorderRecursive(root->left, result);
            postorderRecursive(root->right, result);
            result.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            postorderRecursive(root, result);
            return result;
        }
    };