#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

//? Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* current = dummyNode;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummyNode->next;
    }
};


//? Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

//? Middle of the Linked List
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//? Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


//? Remove Nth Node from End of the List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == NULL) {
            return head->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

//? Reverse Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        while (temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(), ans.end());
        temp = head;
        for (int i = 0; i < ans.size(); i++) {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};

//? Palindrome Linked List
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;

        while (temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0;
        int right = ans.size() - 1;
        while (left < right) {
            if (ans[left] != ans[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

//? Sort Linked List
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};

class TreeNode {
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val) {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

//? Flatten Binary Tree to a Linked List
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


//? Delete the Middle Node of Linked List
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


//? Delete Node in a Linked List
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete nextNode;
    }
};


//? Intersection of Two Linked List
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while (pa != pb) {
            // pa = pa ? pa->next : headB;
            // pb = pb ? pb->next : headA;

            pa = pa == NULL ? headB : pa->next;
            pb = pb == NULL ? headA : pb->next;
        }

        return pa;
    }
};

