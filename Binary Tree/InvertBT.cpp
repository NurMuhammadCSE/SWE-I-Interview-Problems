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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return 0; // return NULL;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        // Swap left and right subtrees
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};


int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    TreeNode* inverted = s.invertTree(root);
    cout << inverted->val << endl;
    cout << inverted->left->val << " " << inverted->right->val << endl;
    cout << inverted->left->left->val << " " << inverted->left->right->val << " " << inverted->right->left->val << " " << inverted->right->right->val << endl;
    return 0;
}
        