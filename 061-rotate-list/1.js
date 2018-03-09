// 61. Rotate List
// https://leetcode.com/problems/rotate-list/description/

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
var rotateRight = function(head, k) {
  const dummyHead = new ListNode(0);
  dummyHead.next = head;

  let n = 0, tail = dummyHead;
  while (tail.next) { 
    tail = tail.next; n++;
  };

  if (k %= n) {
    let pre = dummyHead;
    for (let i = 0; i < n - k; i++) {
      pre = pre.next;
    }
    dummyHead.next = pre.next;
    tail.next = head;
    pre.next = null;
  }
  return dummyHead.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1 , 2, 3, 4, 5]);
let l2 = createLinkedList([]);
let l3 = createLinkedList([1]);
printLinkedList(l1);
printLinkedList(rotateRight(l1, 2));
printLinkedList(l2);
printLinkedList(rotateRight(l2, 0));
printLinkedList(l3);
printLinkedList(rotateRight(l3, 0));
