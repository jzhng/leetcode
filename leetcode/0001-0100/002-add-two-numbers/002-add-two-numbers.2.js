/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  const dummy = new ListNode(0, l1);
  
  let cur = dummy;
  let carry = 0;
  while (l1 && l2) {
     let val = l1.val + l2.val + carry;
     cur.next = new ListNode(val % 10);
     carry = (val - val % 10) /10;
     l1 = l1.next;
     l2 = l2.next;
     cur = cur.next; 
  }
  
  while (l1) {
      let val = l1.val + carry;
      cur.next = new ListNode(val % 10);
      carry = (val - val % 10) /10;
      l1 = l1.next;
      cur = cur.next;
  }
  
  while (l2) {
      let val = l2.val + carry;
      cur.next = new ListNode(val % 10);
      carry = (val - val % 10) /10;
      l2 = l2.next;
      cur = cur.next;
  }
  
  if (carry)
      cur.next = new ListNode(carry);

  return dummy.next;
};
