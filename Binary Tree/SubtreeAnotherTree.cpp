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
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == NULL and t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;

        if (s->val != t->val) {
            return false;
        }

        return isSame(s->left, t->left) and isSame(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        if (isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};


int main(){
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    Solution sol;
    cout << sol.isSubtree(s, t) << endl;
    return 0;
}