#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
  public:
    Node* addOne(Node* head) {
        head = reverseLL(head);
        Node* curr = head;
        int carry = 1;
        while(curr){
            int sum = curr -> data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            
            if(!carry) break;
            if(!curr->next and carry){
                curr->next = new Node(carry);
                break;
            }
            curr = curr -> next;
        }
        return reverseLL(head);
    }
};
