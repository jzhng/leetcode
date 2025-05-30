/**
 * // Definition for a Node.
 * function Node(val,prev,next,child) {
 *    this.val = val;
 *    this.prev = prev;
 *    this.next = next;
 *    this.child = child;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var flatten = function(head) {
  let cur = head;
  while (cur) {
    if (cur.child) {
      let h = flatten(cur.child);
      let t = h;
      while (t.next) {
        t = t.next;
      }

      let next = cur.next;
      cur.next = h;
      h.prev = cur;
      if (next) next.prev = t;
      t.next = next;
      cur.child = null;
    }
    cur = cur.next;
  }
  return head;
};
