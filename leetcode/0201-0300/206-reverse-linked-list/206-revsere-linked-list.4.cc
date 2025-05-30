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
    ListNode* reverse(ListNode *pre, ListNode *curr) {
        if (curr == nullptr) return pre;
        ListNode *next = curr->next;
        curr->next = pre;
        return reverse(curr, next);
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *curr = head;
        return reverse(pre, curr);
    }
};