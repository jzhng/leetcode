// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
  const dummyHead = { next: null };

  let curr = dummyHead, p = l1, q = l2;
  while (p && q) {
    if (p.val <= q.val) {
      curr.next = p;
      p = p.next;
    } else {
      curr.next = q;
      q = q.next;
    }
    curr = curr.next;
  }

  p && (curr.next = p);
  q && (curr.next = q);
  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 4]);
let l2 = createLinkedList([1, 3, 4]);
printLinkedList(l1);
printLinkedList(l2);
printLinkedList(mergeTwoLists(l1, l2));
