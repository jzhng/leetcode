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
  let dummy = { next: head };
  let pre = dummy;

  if (m === n) return head;
  for (let i = 0; i < m - 1; i++) {
   pre = pre.next;
  }

  let cur = pre.next, then = cur.next;
  for (let i = 0; i < n - m ; i++) {
    cur.next = then.next;
    then.next = pre.next;
    pre.next = then;
    then = cur.next;
  }
  return dummy.next;
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
