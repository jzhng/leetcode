#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    bool isPalindrome(ListNode* head) {
        if (!head || ! head->next) return true;

        ListNode *slow = head, *fast = head->next;
        ListNode *reverse = nullptr, *next;

        while (fast) {
            next = slow -> next;
            slow -> next = reverse;
            reverse = slow;

            slow = next;

            if (!fast->next) break;
            fast = fast -> next -> next;
        }
        head->next = slow;
        if (!fast) slow = slow->next;

        while (slow) {
            if (reverse->val != slow->val) {
                return false;
            }
            reverse = reverse->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(1);
    cout << s.isPalindrome(head) << endl;
    return 0;
}
