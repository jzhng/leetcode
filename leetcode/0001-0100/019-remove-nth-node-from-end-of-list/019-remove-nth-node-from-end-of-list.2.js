/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  const dummy = new ListNode(0, head);
  let first = head;
  let second = dummy;
  let i = n;
  while (i--) first = first.next;
  while (first) {
    first = first.next;
    second = second.next;
  }
  second.next = second.next.next;
  return dummy.next;
};

function generateList(arr) {
  let head = null;
  let cur = null;
  for (let i = 0; i < arr.length; i++) {
    const node = new ListNode(arr[i]);
    if (i === 0) head = node;
    if (cur) {
      cur.next = node;
    }
    cur = node;
  }
  return head;
}

// const arr = [1];
// const index = 1;
const arr = [1, 2];
const index = 2;
console.info(removeNthFromEnd(generateList(arr), index));
