/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  const dummy = new ListNode(0, head);
  let slow = dummy.next;
  let fast = dummy.next;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let cur = dummy.next;

  while (cur !== slow) {
    let tmp = cur.next;
    cur.next = dummy.next;
    dummy.next = cur;
    cur = tmp;
  }

  cur = dummy.next;
  if (fast) slow = slow.next;

  while (cur && slow) {
    if (cur.val !== slow.val) return false;
    cur = cur.next;
    slow = slow.next;
  }

  return true;
};
