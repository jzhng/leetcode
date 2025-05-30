/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if (!head || !head.next) return true;

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

  let left = head, right = pre.next;
  while (left && right) {
    if (left.val !== right.val) {
      return false;
    }
    left = left.next;
    right = right.next;
  }
  return true;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 1]);
printLinkedList(l1);
console.info(isPalindrome(l1));
