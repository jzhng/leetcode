#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *fast = head;

        for (int i = 0; i < n; ++i) fast = fast -> next;
        while (fast) {
            fast = fast->next;
            pre = pre->next;
        }
        
        pre->next = pre->next->next;

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head = s.removeNthFromEnd(head, 2);
    for (ListNode *p = head; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}