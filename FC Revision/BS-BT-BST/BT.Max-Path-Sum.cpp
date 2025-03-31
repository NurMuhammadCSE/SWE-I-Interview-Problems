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
    int solve(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));
        // int left = solve(root->left, maxi);
        // int right = solve(root->right, maxi);

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree.
This is because we are using recursion and the maximum depth of the recursion stack will be equal to the height of the tree.
The space complexity can be O(n) in the case of a skewed tree (all nodes are either left or right children).
*/