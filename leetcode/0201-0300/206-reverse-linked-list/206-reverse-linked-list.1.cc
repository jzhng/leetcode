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
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head, *pre = dummy;
        while (cur) {
            pre = cur;
            cur = cur->next;
            pre->next = dummy->next;
            dummy->next= pre;
        }
        if (head) {
            head->next = nullptr;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
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