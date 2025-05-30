// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/description/

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
var addTwoNumbers = function(l1, l2) {
  const s1 = [], s2 = [];
  while (l1) { s1.push(l1.val); l1 = l1.next; }
  while (l2) { s2.push(l2.val); l2 = l2.next; }

  let head = new ListNode(0), carry = 0;
  while (s1.length || s2.length) {
    let a = s1.length ? s1.pop() : 0;
    let b = s2.length ? s2.pop() : 0;
    let sum = a + b + carry;
    carry = Math.floor(sum / 10);
    let node = new ListNode(sum % 10);
    node.next = head.next;
    head.next = node;
  }
  head.val = carry;

  return carry ? head : head.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');

let l1 = createLinkedList([7, 2, 4, 3]);
let l2 = createLinkedList([5, 6, 4]);

// let l1 = createLinkedList([9, 9]);
// let l2 = createLinkedList([1]);
printLinkedList(l1);
printLinkedList(l2);
printLinkedList(addTwoNumbers(l1, l2));

