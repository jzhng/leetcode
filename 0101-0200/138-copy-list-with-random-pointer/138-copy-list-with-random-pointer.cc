#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;

        if (!head) return nullptr;

        Node dummy(0);

        Node *curr = head, *copy = &dummy;
        while (curr) {
            Node *node = new Node(curr->val);
            copy->next = node;
            map[curr] = node;
            curr = curr->next;
            copy = copy->next;
        }

        curr = head;
        copy = dummy.next;
        while (curr) {
            copy->random = map[curr->random];
            curr = curr->next;
            copy = copy->next;
        }

        return dummy.next;
    }
};

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    Solution s;
    Node *copy = s.copyRandomList(head);
    for (Node *p = copy; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}