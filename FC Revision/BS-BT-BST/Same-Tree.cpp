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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        if (isSameTree(p->left, q->left) and isSameTree(p->right, q->right)) {
            return true;
        }
        return false;
    }
};
/*
Time Complexity: O(n) where n is the number of nodes in the tree.
Space Complexity: O(h) where h is the height of the tree. This is because we are using recursion and the maximum depth of the recursion stack will be equal to the height of the tree.
The space complexity can be O(n) in the case of a skewed tree (all nodes are either left or right children).
In that case, the recursion stack will have n function calls, leading to O(n) space complexity.
*/