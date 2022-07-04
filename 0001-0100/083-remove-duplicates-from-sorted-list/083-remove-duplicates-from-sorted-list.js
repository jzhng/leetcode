// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
var deleteDuplicates = function(head) {
  if (!head) return null;

  let pre = head, cur = head.next;
  while (cur) {
    let next = cur.next;
    if (pre.val === cur.val) {
      pre.next = next;
    } else {
      pre = cur;
    }
    cur = next;
  }
  return head;
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

let arr = [1, 2, 2, 2 ,3, 4, 4, 5];
let head = createLinkedList(arr);
printLinkedList(head);
let head2 = deleteDuplicates(head);
printLinkedList(head2);
