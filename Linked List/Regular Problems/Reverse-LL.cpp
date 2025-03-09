#include <bits/stdc++.h>
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
        vector<int> values;
        ListNode* temp = head;

        while (temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;

        for (int i = values.size() - 1; i >= 0; i--) {
            temp->val = values[i];
            temp = temp->next;
        }
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* reversed = obj.reverseList(head);

    while (reversed) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }

    return 0;
}