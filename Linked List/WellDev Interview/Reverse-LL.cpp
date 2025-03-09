#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> result;
        ListNode* temp = head;

        while (temp) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        for (int i = result.size() - 1; i >= 0; i--) {
            temp->val = result[i];
            temp = temp->next;
        }
        return head;
    }
};