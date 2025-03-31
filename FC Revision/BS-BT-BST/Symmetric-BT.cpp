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
    bool isSame(TreeNode* left, TreeNode* right) {
        if (left == NULL and right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        if (isSame(left->left, right->right) and
            isSame(left->right, right->left)) {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        return isSame(root->left, root->right);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree.
This is because we are using recursion and the maximum depth of the recursion stack will be equal to the height of the tree.
*/