/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  const dummy = new ListNode(0, head);
  let cur = head;
  while (cur) {
    let tmp = cur.next;
    cur.next = dummy.next;
    dummy.next = cur;
    cur = tmp;
  }
  if (head) head.next = null;
  return dummy.next;
};
