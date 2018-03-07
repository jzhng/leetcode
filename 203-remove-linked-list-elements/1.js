// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
  let dummy = { next: head }, curr = dummy;
  while (curr.next) {
    if (curr.next.val === val) {
      curr.next = curr.next.next;
    } else {
      curr = curr.next;
    }
  }
  return dummy.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([2, 2, 4, 3, 2]);
printLinkedList(l1);
printLinkedList(removeElements(l1, 2));
