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
    int maxPathSum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        int left = max(0, maxPathSum(root->left, maxi));
        int right = max(0, maxPathSum(root->right, maxi));
        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s;
    cout << s.maxPathSum(root) << endl;
    return 0;
}