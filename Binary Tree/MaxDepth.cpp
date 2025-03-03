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
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};


class Solution {
public: 
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.maxDepth(root) << endl;
    return 0;
}