#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode () : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head = s.reverseList(head);
    for (ListNode *p = head; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    
    return 0;
}