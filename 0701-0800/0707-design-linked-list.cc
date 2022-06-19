
#include <iostream>
using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val): val(val), next(nullptr) {}
    };
    ListNode *head;

public:
    MyLinkedList() : head(new ListNode()) {}
    
    int get(int index) {
        int i = 0;
        ListNode *cur = head->next;
        while (cur) {
            if (i++ == index) {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head->next;
        head->next = node;
    }
    
    void addAtTail(int val) {
        ListNode* pre = head;
        while (pre->next) {
            pre = pre->next;
        }
        pre->next = new ListNode(val);
    }
    
    void addAtIndex(int index, int val) {
        int i = 0;
        ListNode *pre = head;
        while (pre) {
            if (i++ == index) {
                ListNode *node = new ListNode(val);
                node->next = pre->next;
                pre->next = node;
                return;
            }
            pre = pre->next;
        }
    }
    
    void deleteAtIndex(int index) {
        int i = 0;
        ListNode *pre = head;
        while (pre->next) {
            if (i++ == index) {
                ListNode *t = pre->next;
                pre->next = pre->next->next;
                delete t;
                return;
            }
            pre = pre->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
*/

int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
    return 0;
}