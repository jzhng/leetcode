struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    ListNode* reverseBetween(ListNode* head, ListNode *after) {
        if (!head || !head->next || head->next == after) return head;

        ListNode *revesed = reverseBetween(head->next, after);
        head->next->next = head;
        head->next = after;
        return revesed;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode *pre = &dummy, *after = head;

        int i = 1;
        while (i <= right) {
            if (i < left) {
                pre = pre->next;
            }
            after = after->next;
            ++i;
        }
        pre->next = reverseBetween(pre->next, after);
        return dummy.next;
    }
};