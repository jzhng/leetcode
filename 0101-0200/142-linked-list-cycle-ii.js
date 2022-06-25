/**
 * @param {ListNode} head
 * @return {ListNode}
 */
// var detectCycle = function(head) {
//   let cur = head;
//   const visited = new Set();
//   while (cur) {
//     if (visited.has(cur)) return cur;
//     visited.add(cur);
//     cur = cur.next;
//   }
//   return null;
// };

var detectCycle = function(head) {
  let fast = head;
  let slow = head;
  while (fast) {
    slow = slow.next;
    if (fast.next) {
      fast = fast.next.next;
    } else {
      break;
    }
    if (fast === slow) {
      let ptr = head;
      while (ptr !== slow) {
        ptr = ptr.next;
        slow = slow.next;
      }
      return ptr;
    }
  }
  return null;
};
