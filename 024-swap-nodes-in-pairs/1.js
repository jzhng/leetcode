// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
var swapPairs = function(head) {
  const dummyHead = new ListNode(0);
  dummyHead.next = head;

  let pre = dummyHead, p = head;
  while (p && p.next) {
    let next = p.next;
    let after = next.next;

    next.next = p;
    p.next = after;
    pre.next = next;

    pre = p;
    p = pre.next;
  }
  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 4]);
printLinkedList(l1);
printLinkedList(swapPairs(l1));
