#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode*> visited;
    //     ListNode* cur = headA;
    //     while (cur) {
    //         visited.insert(cur);
    //         cur = cur->next;
    //     }

    //     cur = headB;
    //     while (cur) {
    //         if (visited.count(cur) == 1) {
    //             return cur;
    //         }
    //         cur = cur->next;
    //     }

    //     return nullptr;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while (curA != curB) {
            curA = (curA == nullptr) ? headB : curA->next;
            curB = (curB == nullptr) ? headA : curB->next;
        }
        return curA;
    }
};

int main() {
    Solution s;
    ListNode *headA = new ListNode(1);
    headA -> next = new ListNode(2);
    headA -> next -> next = new ListNode(3);
    ListNode *headB = new ListNode(4);
    headB -> next = new ListNode(5);
    headB -> next -> next = headA -> next;
    cout << s.getIntersectionNode(headA, headB)->val << endl;
    return 0;
}