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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        // if (leftHeight == -1)
        //     return -1;

        int rightHeight = height(root->right);
        // if (rightHeight == -1)
        //     return -1;

        // if (abs(leftHeight - rightHeight) > 1) {
        //     return -1;
        // }

        if (leftHeight == -1 || rightHeight == -1 ||
            abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) {
            return false;
        }
        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}