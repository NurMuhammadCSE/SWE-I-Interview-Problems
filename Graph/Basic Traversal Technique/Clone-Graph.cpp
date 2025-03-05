#include<bits/stdc++.h>
using namespace std;

// Graph Node Structure
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
    }
};

// Solution Class
class Solution {
public:
    unordered_map<Node*, Node*> cloneMap; // পুরাতন নোড -> নতুন নোড স্টোর করার জন্য

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // যদি গ্রাফ খালি থাকে

        // যদি নোড আগেই ক্লোন করা হয়ে থাকে, তাহলে সেটাই ফেরত দেই
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        if (cloneMap.count(node)) {
            return cloneMap[node];
        }

        // নতুন নোড তৈরি করি
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode; // ম্যাপে রেখে দেই

        // সকল নোডের জন্য DFS কল করি এবং সংযুক্ত করি
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution obj;
    Node* cloneNode = obj.cloneGraph(node1);

    return 0;
}