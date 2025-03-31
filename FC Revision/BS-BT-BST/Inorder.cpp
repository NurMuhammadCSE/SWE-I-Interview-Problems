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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
/*
Time Complexity: O(n) where n is the number of nodes in the tree.
Space Complexity: O(h) where h is the height of the tree. This is because we are using recursion and the maximum depth of the recursion stack will be equal to the height of the tree.
The space complexity can be O(n) in the case of a skewed tree (all nodes are either left or right children).
In that case, the recursion stack will have n function calls, leading to O(n) space complexity.
*/