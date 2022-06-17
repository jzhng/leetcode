// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
  const dummyHead = new ListNode(0);
  dummyHead.next = head;

  let pre = dummyHead, curr = head;
  while (curr) {
    while (curr.next && curr.val === curr.next.val) {
      curr = curr.next;
    }

    if (pre.next === curr) {
      pre = pre.next;
    } else {
      pre.next = curr.next;
    }
    curr = curr.next;
  }
  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 3, 4, 4, 5]);
let l2 = createLinkedList([1, 1, 1, 2, 3]);
printLinkedList(l1);
printLinkedList(deleteDuplicates(l1));
printLinkedList(l2);
printLinkedList(deleteDuplicates(l2));
