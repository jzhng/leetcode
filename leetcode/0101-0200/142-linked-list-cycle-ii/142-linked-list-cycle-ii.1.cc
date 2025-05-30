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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        while (head) {
            if (st.count(head)) return head;
            st.insert(head);
            head = head->next;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = head -> next;
    cout << s.detectCycle(head)->val << endl;
}