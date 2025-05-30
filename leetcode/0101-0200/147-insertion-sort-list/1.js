// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/description/

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
var insertionSortList = function(head) {
  const dummyHead = new ListNode(0);

  let curr = head;
  while (curr) {
    let p = dummyHead, next = p.next;
    while (next && next.val <= curr.val) {
      p = next;
      next = p.next;
    }

    let _t = curr.next;
    curr.next = p.next;
    p.next = curr;

    curr = _t;
  }
  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([4, 3, 5, 7, 2, 1]);
printLinkedList(l1);
printLinkedList(insertionSortList(l1));
