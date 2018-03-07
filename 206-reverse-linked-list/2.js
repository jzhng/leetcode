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
var reverseList = function(head) {
  let pre = null, cur = head;
  while (cur) {
    let next = cur.next;
    cur.next = pre;
    pre = cur;
    cur = next;
  }
  return pre;
};

function ListNode(val) {
  this.val = val;
  this.next = null;
}

function createLinkedList(arr) {
  const n = arr.length;
  if (n === 0) return null;
  let head = new ListNode(arr[0]);
  let cur = head;
  for (let i = 1; i < n; i++) {
    cur.next = new ListNode(arr[i]);
    cur = cur.next;
  }
  return head;
}

function printLinkedList(head) {
  let cur = head, s = '';
  while (cur) {
    s += `${cur.val} -> `;
    cur = cur.next;
  }
  s += 'null';
  console.info(s);
}

let arr = [1, 2, 3, 4, 5];
let head = createLinkedList(arr);
printLinkedList(head);
let head2 = reverseList(head);
printLinkedList(head2);
