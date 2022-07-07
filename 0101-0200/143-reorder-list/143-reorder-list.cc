struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        auto pre = head;
        while (pre->next->next) {
            pre = pre->next;
        }

        auto tail = pre->next;
        pre->next = nullptr;
        tail->next = head->next;
        head->next = tail;
        reorderList(tail->next);
    }
};