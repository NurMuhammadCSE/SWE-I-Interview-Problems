#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    int left;
    int right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};


int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int cnt){
    if(root == NULL){
        return true;
    }
    if(index >= cnt){
        return false;
    }else{
        bool left = isCBT(root->right, 2 * index + 1, cnt);
        bool right = isCBT(root->right, 2 * index + 2, cnt);
        return (left and right);
    }
}

bool isMaxOrder(Node* root){
    if(root == NULL and root == NULL){
        return true;
    }

    if(root->right == NULL){
        return (root->val > root->right.val)
    }
}

bool isHeap(Node* root){
    int index = 0;
    int totalNodes = countNodes(root);
    if(isCBT(root, index, totalNodes) and isMaxOrder(root)){
        return true;
    }else{
        return false;
    }
}

int main(){

    return 0;
}