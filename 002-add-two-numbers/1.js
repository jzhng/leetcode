// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/

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
  let carry = 0, dummy = new ListNode(0);

  let pre = null, curr = dummy;
  while (l1 || l2) {
    let a = l1 ? l1.val : 0;
    let b = l2 ? l2.val : 0;
    let sum = a + b + carry;
    carry = Math.floor(sum / 10);

    curr.next = new ListNode(sum % 10);
    curr = curr.next;

    l1 && (l1 = l1.next);
    l2 && (l2 = l2.next);
  }

  if (carry) curr.next = new ListNode(carry);
  return dummy.next;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');

let l1 = createLinkedList([2, 4, 3]);
let l2 = createLinkedList([5, 6, 6]);
// let l1 = createLinkedList([1, 8]);
// let l2 = createLinkedList([5]);
// let l1 = createLinkedList([5]);
// let l2 = createLinkedList([1, 8]);
printLinkedList(l1);
printLinkedList(l2);
printLinkedList(addTwoNumbers(l1, l2));
