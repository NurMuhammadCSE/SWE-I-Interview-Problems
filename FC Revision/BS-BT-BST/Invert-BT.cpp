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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree.
This is because we are using recursion and the maximum depth of the recursion stack will be equal to the height of the tree.
The space complexity can be O(n) in the case of a skewed tree (all nodes are either left or right children).

*/