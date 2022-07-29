class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyHead(0, head);
        ListNode *pre = &dummyHead, *curr = head, *next = nullptr;

        while (curr && curr->next) {
            next = curr->next;
            if (curr->val == next->val) {
                while (next && curr->val == next->val) {
                    curr = next;
                    next = curr->next;
                }
                pre->next = next;
            } else {
                pre = curr;
            }
            curr = next;
        }

        return dummyHead.next;
    }
};
