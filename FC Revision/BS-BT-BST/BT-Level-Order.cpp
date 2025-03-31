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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};
/*
Time Complexity: O(n) where n is the number of nodes in the tree.
Space Complexity: O(n) for the queue used to store the nodes at each level.
In the worst case, the queue can store all the nodes at the last level of the tree.
In a complete binary tree, the last level can have up to n/2 nodes, leading to O(n) space complexity.
*/