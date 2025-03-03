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
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;

        if (left->val != right->val) return false;

        return isMirror(left->left, right->right) && // ✅ বাম-ডান মিলিয়ে চেক
                isMirror(left->right, right->left);  // ✅ ডান-বাম মিলিয়ে চেক
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // খালি ট্রি হলে Symmetric
        return isMirror(root->left, root->right);
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    cout << s.isSymmetric(root) << endl;
    return 0;
}