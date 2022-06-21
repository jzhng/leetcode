#include <iostream>
using namespace std;

struct  ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode(), *cur = res;
        while (l1 || l2) {
            int sum = (l1? l1-> val : 0) + (l2 ? l2->val : 0)+ carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry != 0) {
            cur->next = new ListNode(carry);
        }

        return res->next;
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1 -> next = new ListNode(2);
    l1 -> next -> next = new ListNode(3);
    ListNode *l2 = new ListNode(4);
    l2 -> next = new ListNode(5);
    l2 -> next -> next = new ListNode(7);
    ListNode *sum = s.addTwoNumbers(l1, l2);
    for (ListNode *p = sum; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}