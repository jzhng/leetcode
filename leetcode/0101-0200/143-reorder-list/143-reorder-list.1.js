// 143. Reorder List
// https://leetcode.com/problems/reorder-list/description/

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
  if (!head) return;

  let arr = [], p = head.next;
  while (p) { 
    arr.push(p);
    p = p.next;
  }

  p = head;
  while (arr.length > 1) {
    p.next = arr.pop();
    p.next.next = arr.shift();
    p = p.next.next;
  }

  let tail = arr.pop();
  if (tail) {
    tail.next = null;
  }
  p.next = tail;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 4, 5]);
printLinkedList(l1);
reorderList(l1);
printLinkedList(l1);
