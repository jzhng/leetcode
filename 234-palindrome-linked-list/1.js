// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/description/

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
  let p = head, arr = [];

  while (p) {
    arr.push(p);
    p = p.next;
  }

  while (arr.length > 1) {
    let p = arr.shift();
    let q = arr.pop();
    if (p.val !== q.val) {
      return false;
    }
  }
  return true;
};

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([]);
printLinkedList(l1);
console.info(isPalindrome(l1));
