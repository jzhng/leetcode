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

var sortList = function(head) {
  let p = head, n = 0;
  while (p) { p = p.next; n++;}

  const dummyHead = new ListNode(0);
  dummyHead.next = head;

  for (let step = 1; step < n; step += step) {
    let curr = dummyHead.next, tail = dummyHead, left, right;
    while (curr) {
      left = curr;
      right = split(left, step);
      curr = split(right, step);
      tail = merge(left, right, tail);
    }
  }

  return dummyHead.next;
};

function split(head, n) {
  let p = head;
  for (let i = 1; p && i < n; i++) {
    p = p.next;
  }

  if (p) {
    let next = p.next;
    p.next = null;
    return next;
  }

  return null;
}

function merge(l1, l2, head) {
  let p = head;
  while (l1 && l2) {
    if (l1.val <= l2.val) {
      p.next = l1;
      l1 = l1.next;
    } else {
      p.next = l2;
      l2 = l2.next;
    }
    p = p.next;
  }
  p.next = l1 ? l1 : l2;

  while (p.next) { 
    p = p.next;
  }
  return p;
}

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([10, 4, 3, 5, 7, 6, 2, 1, 9, 8]);
printLinkedList(l1);
printLinkedList(sortList(l1));
