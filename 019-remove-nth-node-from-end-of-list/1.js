// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  const dummyHead = new ListNode(0);
  dummyHead.next = head;
  
  let p = dummyHead, q = dummyHead;
  for (let i = 0; i <= n && q; i++) {
    q = q.next;
  }

  while (q) {
    p = p.next;
    q = q.next;
  }
  p.next = p.next.next;

  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1 , 2, 3, 4, 5]);
printLinkedList(l1);
printLinkedList(removeNthFromEnd(l1, 2));
