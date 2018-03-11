// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {

  const k = lists.length;
  for (let sz = 1; sz <= k; sz += sz) {
    for (let i = 0; i + sz < k; i += sz + sz) {
      let l1 = lists[i], l2 = lists[i + sz];
      lists[i] = merge(l1, l2);
    }
  }

  return lists[0] || null;
    
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
  p.next = l1 ? l1 : l2;

  return dummyHead.next;
}

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 4, 5, 6, 7, 8]);
let l2 = createLinkedList([3, 5, 6, 9]);
let l3 = createLinkedList([2, 4, 8, 10, 11, 12, 19]);
let l4 = createLinkedList([0, 1, 2, 3, 4, 5, 6, 7]);
const lists = [l1, l2, l3, l4];
printLinkedList(l1);
printLinkedList(l2);
printLinkedList(l3);
printLinkedList(l4);
printLinkedList(mergeKLists(lists));
