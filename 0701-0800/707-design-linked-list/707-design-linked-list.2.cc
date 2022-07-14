#include <iostream>
using namespace std;

class MyLinkedList {
    struct DoublyLinkedNode {
        int val;
        DoublyLinkedNode *prev, *next;
        DoublyLinkedNode(): val(0), prev(nullptr), next(nullptr) {}
        DoublyLinkedNode(int val): val(val), prev(nullptr), next(nullptr) {}
    };
    DoublyLinkedNode *head;
public:
    MyLinkedList(): head(new DoublyLinkedNode()) {}
    
    int get(int index) {
        DoublyLinkedNode *cur = head->next;
        for (int i = 0; i <= index && cur; ++i) {
            if (i == index) return cur->val;
            cur = cur->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        DoublyLinkedNode *node = new DoublyLinkedNode(val);
        if (head->next) {
            head->next->prev = node;
        }
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    
    void addAtTail(int val) {
        DoublyLinkedNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        
        DoublyLinkedNode *node = new DoublyLinkedNode(val);
        tail->next = node;
        node->prev = tail;
    }
    
    void addAtIndex(int index, int val) {
        DoublyLinkedNode *node = new DoublyLinkedNode(val);

        DoublyLinkedNode *pre = head;
        for (int i = 0; i < index && pre; ++i) {
            pre = pre->next;
        }

        if (!pre) return;

        node->next = pre->next;
        node->prev = pre;
        if (pre->next) {
            pre->next->prev = node;
        }
        pre->next = node;
    }
    
    void deleteAtIndex(int index) {
        DoublyLinkedNode *cur = head->next;
        for (int i = 0; i < index && cur; ++i) {
            cur = cur->next;
        }

        if (!cur) return;
        cur->prev->next = cur->next;
        if (cur->next) {
            cur->next->prev = cur->prev;
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
    obj->addAtIndex(1, 2);
    // for (int i = 0; i < 3; ++i) {
    //     cout << obj->get(i) << endl;
    // }
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    //     for (int i = 0; i < 3; ++i) {
    //     cout << obj->get(i) << endl;
    // }
    cout << obj->get(1) << endl;
    return 0;
}