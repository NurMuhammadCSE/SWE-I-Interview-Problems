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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                level.push_back(currentNode->val);

                if (currentNode->left != NULL) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != NULL) {
                    q.push(currentNode->right);
                }
            }

            // If leftToRight is false, reverse the current level
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }

            result.push_back(level);
            leftToRight = !leftToRight; // Toggle the direction next level
        }

        return result;
    }
};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> result = s.zigzagLevelOrder(root);
    for (vector<int> v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}