#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) {
            return false;
        }
        return true;
    }
};