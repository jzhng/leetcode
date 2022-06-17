/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
  if (!head || !head.next) return;

  let slow = head, fast = head.next;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let pre = slow, curr = pre.next, then = curr.next;
  while (then) {
    curr.next = then.next;
    then.next = pre.next;
    pre.next = then;
    then = curr.next;
  }

  let p = head, q = pre.next;
  while (p !== pre) {
    pre.next = q.next;
    q.next = p.next;
    p.next = q;

    p = q.next;
    q = pre.next;
  }
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1]);
printLinkedList(l1);
reorderList(l1);
printLinkedList(l1);
