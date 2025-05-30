// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
  let cnt = 1, pre = null, cur = head;
  let before = null, tail = null;

  if (m === n) return head;
  while (cur && cnt <= n) {
    let next = cur.next;
    if (cnt === m) {
      before = pre;
      tail = cur;
    } else if (cnt > m) {
      cur.next = pre;
    }
    pre = cur;
    cur = next;
    cnt++;
  }

  before && (before.next = pre);
  tail && (tail.next = cur);

  return m === 1 ? pre : head;
};

const l5 = {val: 5, next: null };
const l4 = {val: 4, next: l5 };
const l3 = {val: 3, next: l4 };
const l2 = {val: 2, next: l3 };
const l1 = {val: 1, next: l2 };
const r2 = {val: 5, next: null };
const r1 = {val: 3, next: r2 };
const s3 = {val: 3, next: null };
const s2 = {val: 2, next: s3 };
const s1 = {val: 1, next: s2 };
const head1 = l1;
const head2 = {val: 1, next: null };
const head3 = r1;
const head4 = s1;
console.info(reverseBetween(head1, 2, 4));
console.info(reverseBetween(head2, 1, 1));
console.info(reverseBetween(head3, 1, 1));
console.info(reverseBetween(head3, 1, 2));
console.info(reverseBetween(head4, 1, 2));
