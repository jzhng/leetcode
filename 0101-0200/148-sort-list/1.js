// 148. Sort List
// https://leetcode.com/problems/sort-list/description/

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

// Space O(n) solution, not good
var sortList = function(head) {
  var arr = [], p = head, pre;
  while (p) {
    arr.push(p);
    let pre = p;
    p = p.next;
    pre.next = null;
  }

  const n = arr.length;
  for (let sz = 1; sz <= n; sz += sz) {
    for (let i = 0; i + sz < n; i += sz + sz) {
      let l1 = arr[i], l2 = arr[i + sz];
      arr[i] = merge(l1, l2);
    }
  }

  return head ? arr[0] : null;
};

function merge(l1, l2) {
  const dummyHead = new ListNode(0);
  dummyHead.next = null;

  let p = dummyHead;
  while (l1 && l2) {
    if (l1.val <= l2.val) {
      p.next = l1;
      l1 = l1.next;
    } else {
      p.next = l2;
      l2 = l2.next;
    }
    p = p.next;
  }
  l1 && (p.next = l1);
  l2 && (p.next = l2);

  return dummyHead.next;
}

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([10, 4, 3, 5, 7, 6, 2, 1, 9, 8]);
printLinkedList(l1);
printLinkedList(sortList(l1));
