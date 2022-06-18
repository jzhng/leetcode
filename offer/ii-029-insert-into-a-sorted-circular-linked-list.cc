#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *insert = new Node(insertVal);

        if (!head) {
            insert->next = insert;
            return insert;
        }

        Node *pre = nullptr, *cur = head;
        bool insert_found = false;
        while (cur->next != head && !insert_found) {
            pre = cur;
            cur = cur->next;
            if (pre->val <= insertVal && insertVal <= cur->val ||
                insertVal <= cur->val && cur->val < pre->val ||
                cur->val < pre->val && pre->val <= insertVal) {
                insert_found = true;
            }
        }

        if (insert_found) {
            insert->next = cur;
            pre->next = insert;
        } else {
            insert->next = head;
            cur->next = insert;
        }

        return head;
    }
};

int main() {
    Solution s;
    Node *head = new Node(3);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = head;

    head = s.insert(head, 6);
    Node *cur = head;
    cout << cur -> val << " ";
    cur = cur->next;
    while (cur != head) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}