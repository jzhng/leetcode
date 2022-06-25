/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
  if (!head) return null;
  const len = getLength(head);
  let tail = head;
  while (tail && tail.next) {
      tail = tail.next;
  }
  
  let cur = head;
  for (i = 0; i < k % len; i++) cur = cur.next;
  
  let res = cur.next;
  
  tail.next = head;
  cur.next = null;
  
  return res;
};

function getLength(head) {
  let i = 0;
  while (head) {
      i++;
      head = head.next;
  }
  return i;
}

const {createLinkedList, printLinkedList, ListNode} = require('../util');

const head = createLinkedList([1]);
printLinkedList(head);
printLinkedList(rotateRight(head, 0));
