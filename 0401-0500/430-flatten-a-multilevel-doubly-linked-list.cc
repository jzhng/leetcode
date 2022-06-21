#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        while (curr) {
            if (curr->child) {
                Node *child = curr->child;
                while (child->next) {
                    child = child->next;
                }
                child->next = curr->next;
                if (curr->next) {
                    curr->next->prev = child;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;  
    }
};

int main() {
    Node *head = new Node();
    head->val = 1;
    head->child = new Node();
    head->child->val = 2;
    head->child->child = new Node();
    head->child->child->val = 3;
    head->child->child->next = new Node();
    head->child->child->next->val = 4;
    head->child->child->next->next = new Node();
    head->child->child->next->next->val = 5;
    head->child->child->next->next->next = new Node();
    head->child->child->next->next->next->val = 6;
    Solution s;
    s.flatten(head);
    for (Node *p = head; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}