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

module.exports = { createLinkedList, printLinkedList };
