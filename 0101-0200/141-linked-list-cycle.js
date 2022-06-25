/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

 function ListNode(val) {
   this.val = val;
   this.next = null;
 }

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
  let l = head;
  let r = head;
  while (l && l.next && r.next && r.next.next) {
      l = l.next;
      r = r.next.next;
      if (l === r) return true;
  }
  return false;
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

const arr = [-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5];
console.info(hasCycle(generateList(arr)));
