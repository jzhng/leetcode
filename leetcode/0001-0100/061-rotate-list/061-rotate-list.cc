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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode *tail = head;
        int length = 1;
        while (tail->next) { 
            tail = tail->next;
            ++length;
        }

        int step = k % length;
        if (step == 0) return head;

        ListNode *fast = head, *slow = head;
        while (step-- > 0) {
            fast = fast->next;
        }
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        tail->next = head;

        ListNode *res = slow->next;
        slow->next = nullptr;
        return res;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = s.rotateRight(head, 200000000);
    for (auto p = head; p; p = p->next) {
        cout << p -> val << " ";
    }
    cout << endl;

    return 0;
}
