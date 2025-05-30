// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
  const dummyHead = new ListNode(0);
  dummyHead.next = head;

  let pre = dummyHead, curr = head;
  while (curr && curr.next) {
    let count = 0, after = curr;
    while (count < k && after) {
      after = after.next;
      count++;
    }
    if (count < k && !after) break;

    let then = curr.next;
    while (then !== after) {
      curr.next = then.next;
      then.next = pre.next;
      pre.next = then;
      then = curr.next;
    }
    pre = curr;
    curr = after;
  }

  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 4]);
let l2 = createLinkedList([1, 2, 3, 4, 5]);
printLinkedList(l1);
printLinkedList(reverseKGroup(l1, 2));
printLinkedList(l2);
printLinkedList(reverseKGroup(l2, 2));
