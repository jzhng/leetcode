// 86. Partition List
// https://leetcode.com/problems/partition-list/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
  if (!head) return null;

  let dummy = { next: head};
  let pre = dummy, cur = head, after, tail;
  while (cur) {
    let next = cur.next;
    if (cur.val < x) {
      pre = cur;
    } else {
      if (!after) {
        after = tail = cur;
      } else {
        tail.next = cur;
        tail = cur;
      }
      cur.next = null;
      pre.next = next;
    }
    cur = next;
  }

  pre.next = after;
  return dummy.next;
};

const {createLinkedList, printLinkedList} = require('../util');

const arr1 = [1, 4, 3, 2 ,5, 2], x1 = 3;
const arr2 = [2, 3, 1], x2 = 2;
let head1 = createLinkedList(arr1);
let head2 = createLinkedList(arr2);
printLinkedList(head1);
printLinkedList(partition(head1, x1));
printLinkedList(head2);
printLinkedList(partition(head2, x2));
