// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/description/

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
var oddEvenList = function(head) {
  if (!head) return null;

  var odd = head;
  var even = head.next;
  var evenHead = even;
  while (even && even.next) {
    odd.next = even.next;
    odd = odd.next;
    even.next = odd.next;
    even = even.next;
  }
  odd.next = evenHead;
  return head;
};

const {createLinkedList, printLinkedList} = require('../util');

const arr1 = [1, 2, 3, 4, 5];
let head1 = createLinkedList(arr1);
printLinkedList(head1);
printLinkedList(oddEvenList(head1));
