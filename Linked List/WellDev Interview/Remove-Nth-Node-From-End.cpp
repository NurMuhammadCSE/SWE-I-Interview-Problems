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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

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


//? 🔹 সমাধান ১: Two Pass Approach (O(N) Time, O(1) Space)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        int length = 0;
        
        // Step 1: লিস্টের দৈর্ঘ্য বের করা
        while (temp->next) {
            length++;
            temp = temp->next;
        }
        
        // Step 2: মুছতে হবে (length - n) তম নোডের পরের নোড
        temp = dummy;
        for (int i = 0; i < length - n; i++) {
            temp = temp->next;
        }
        
        // Step 3: নোড মুছে ফেলা
        temp->next = temp->next->next;
        
        return dummy->next;
    }
};



//? 🔹 সমাধান ২: One Pass Approach (O(N) Time, O(1) Space)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 1: প্রথম পয়েন্টারকে n+1 স্টেপ এগিয়ে নেওয়া
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Step 2: দুটি পয়েন্টার একসাথে এগিয়ে নিয়ে যাওয়া
        while (first) {
            first = first->next;
            second = second->next;
        }

        // Step 3: নোড মুছে ফেলা
        second->next = second->next->next;
        
        return dummy->next;
    }
};
    

