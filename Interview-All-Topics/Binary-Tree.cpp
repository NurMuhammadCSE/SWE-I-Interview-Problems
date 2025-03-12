#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//? Maximum Depth of Binary Tree
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

//? Same Tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


//? Symmetric Tree

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


//? Invert/Flip Binary Tree
 
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

//? Binary Tree Maximum Path Sum

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


//? BT Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                ans.push_back(curr->val);

                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};


//? ZigZag Level Order Traversal

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


//? Subtree another Subtree

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


//? Validate Binary Search Tree

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* prev = NULL;

        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();

            if (prev != NULL && root->val <= prev->val)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};

//? Kth Smallest Element in a BST



//? Lowest Common Ancestor

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
    }
};


//? Balanced Binary Tree
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

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
    